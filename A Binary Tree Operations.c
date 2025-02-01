#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct stack{
    struct node** array;
    int top;
};

struct stack* createStack(int size){
    struct stack *Stack = (struct stack*)malloc(sizeof(struct stack));
    Stack->array = (struct node**)malloc(size*sizeof(struct node*));
    Stack->top = -1;
    return Stack;
}

void push(struct stack *Stack, struct node* Node){
    Stack->array[++Stack->top] = Node;
}

struct node* pop(struct stack* Stack){
    if(Stack->top==-1){
        return NULL;
    }
    return Stack->array[Stack->top--];
}

int isStackEmpty(struct stack* Stack){
    return Stack->top==-1;
}

struct node* createNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}



struct node* insertLevelOrder(int arr[], int i, int n){
    if(i>=n || arr[i]==-1) return NULL;
    
    struct node* root = createNode(arr[i]);
    root->left = insertLevelOrder(arr,2*i+1, n);
    root->right = insertLevelOrder(arr, 2*i+2, n);
    return root;
}

int zigzagsum(struct node* root){
    if(root==NULL){
        return 0;
    }
    
    struct stack* currentLevel = createStack(1000);
    struct stack* nextLevel = createStack(1000);
    
    int L2R = 1, sum =0;
    push(currentLevel, root);
    
    while(!isStackEmpty(currentLevel)){
        struct node* temp = pop(currentLevel);
        printf("%d ", temp->data);
        sum+=temp->data;
        
        if(L2R){
            if(temp->left) push(nextLevel, temp->left);
            if(temp->right) push(nextLevel, temp->right);
        }else{
            if(temp->right) push(nextLevel, temp->right);
            if(temp->left) push(nextLevel, temp->left);
        }
        
        if(isStackEmpty(currentLevel)){
            L2R = !L2R;
            struct stack* temp = currentLevel;
            currentLevel = nextLevel;
            nextLevel = temp;
        }
    }
    
    printf("\nZigzag sum : %d\n", sum);
    return sum;
}

void preorderTraversal(struct node* root){
    if(root==NULL) return;
    
    printf("%d ",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(struct node* root){
    if(root==NULL) return;
    
    preorderTraversal(root->left);
    printf("%d ",root->data);
    preorderTraversal(root->right);
}

void postorderTraversal(struct node* root){
    if(root==NULL) return;
    
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    printf("%d ",root->data);
}

struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    // Search left or right subtree
    struct node* leftSearch = search(root->left, key);
    if (leftSearch != NULL) return leftSearch;
    return search(root->right, key);
}

int countNodes(struct node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(struct node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void mirror(struct node* root) {
    if (root == NULL) return;
    struct node* temp;
    mirror(root->left);
    mirror(root->right);
    
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int isBalanced(struct node* root){
    if(root==NULL) return 1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return abs(leftHeight-rightHeight)<=1 && isBalanced(root->left) && isBalanced(root->right);
}

#define max(a,b) ((a)>(b)?(a):(b))

int diameter(struct node* root) {
    if (root == NULL) return 0;

    int leftHeight = height(root->left);  // Height of left subtree
    int rightHeight = height(root->right); // Height of right subtree
    int leftDiameter = diameter(root->left);  // Diameter of left subtree
    int rightDiameter = diameter(root->right); // Diameter of right subtree

    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}


int main(){
    int n;
    printf("Enter the number of nodes in a tree:\n");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    char input[100];
    for(int i=0; i<n; i++){
        scanf("%s",input);
        if(strcmp(input, "NULL")==0){
            arr[i]=-1;
        }else{
            arr[i] = atoi(input);
        }
    }
    
    struct node* root = insertLevelOrder(arr,0,n);
    free(arr);
    printf("\nzigzag traversal\n");
    zigzagsum(root);
    
    printf("preorderTraversal :\n");
    preorderTraversal(root);
    printf("\ninorderTraversal :\n");
    inorderTraversal(root);
    printf("\npostorderTraversal :\n");
    postorderTraversal(root);
    
    struct node* result = search(root, 5);
    if(result!=NULL){
        printf("\nfound %d", result->data);
    }else{
        printf("\nnot found %d", result->data);
    }
    
    printf("\ncount nodes: %d",countNodes(root));
    printf("\nHeight of the tree: %d",height(root));
    if(isBalanced(root)){
        printf("\nTree is Balanced\n");
    }else{
        printf("Tree is unbalanced\n");
    }
    
    printf("Diameter of the tree : %d\n",diameter(root));
    return 0;
    
}
