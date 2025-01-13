/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void preorderTraversal(struct TreeNode* root, int *count){
    if(root==NULL) return;
    (*count)++;
    preorderTraversal(root->left,count);
    preorderTraversal(root->right, count);
}
int countNodes(struct TreeNode* root) {
    if(root==NULL){
        return 0;
    }
    int count =0 ;
    preorderTraversal(root,&count);
    return count;
}
