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
void preorderHelper(struct TreeNode* root, int* result, int* index){
    if(root==NULL) return;
    result[(*index)++] = root->val;
    preorderHelper(root->left, result, index);
    preorderHelper(root->right, result, index);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    if(root==NULL){
        *returnSize=0;
        return NULL;
    }

    int *result = (int*)malloc(100*sizeof(int));
    int index =0;
    preorderHelper(root, result, &index);
    *returnSize=index;
    return result;

}
