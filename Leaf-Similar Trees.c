/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void findleaves(struct TreeNode* root, int *leaves, int*size){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        leaves[(*size)++]=root->val;
        return;
    }
    findleaves(root->left, leaves, size);
    findleaves(root->right, leaves, size);
}

bool CompareLeaves(int *array1, int size1, int *array2, int size2){
    if(size1!=size2) return false;
    for(int i=0; i<size1; i++){
        if(array1[i]!=array2[i]) return false;
    }
    return true;
}
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int *array1 = (int*)malloc(200*sizeof(int));
    int *array2 = (int*)malloc(200*sizeof(int));
    int size1=0,size2=0;
    findleaves(root1,array1,&size1);
    findleaves(root2,array2,&size2);
    bool result =  CompareLeaves(array1,size1,array2,size2);
    free(array1);
    free(array2);
    return result;
}
