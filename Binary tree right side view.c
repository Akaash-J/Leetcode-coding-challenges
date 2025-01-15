/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct queueNode{
    struct TreeNode* node;
    int level;
    struct queueNode* next;
};
struct queue{
    struct queueNode* front;
    struct queueNode* rear;
};
struct queueNode* newqueueNode(struct TreeNode* node, int level){
    struct queueNode* newnode = (struct queueNode*)malloc(sizeof(struct queueNode));
    newnode->node = node;
    newnode->level = level;
    newnode->next = NULL;
    return newnode;
}
struct queue* createqueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
void enqueue(struct queue* q, struct TreeNode* node, int level){
    struct queueNode* temp = newqueueNode(node, level);
    if(q->rear == NULL){
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
struct queueNode* dequeue(struct queue* q){
    if(q->front == NULL) return NULL;
    struct queueNode* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL) q->rear=NULL;
    return temp;
}
int isqueueEmpty(struct queue* q){
    return q->front == NULL;
}
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if(root==NULL){
        *returnSize = 0;
        return NULL;
    }
    struct queue* q = createqueue();
    enqueue(q,root, 0);
    int* result = (int*)malloc(200*sizeof(int));
    int maxlevel = -1;
    *returnSize = 0;
    while (!isqueueEmpty(q)) {
        struct queueNode* current = dequeue(q);
        struct TreeNode* currentNode = current->node;
        int level = current->level;

        if (level > maxlevel) {
            result[(*returnSize)++] = currentNode->val;
            maxlevel = level;
        }

        if (currentNode->right != NULL) enqueue(q, currentNode->right, level + 1);
        if (currentNode->left != NULL) enqueue(q, currentNode->left, level + 1);

        free(current); 
}
free(q);
return result;
}
