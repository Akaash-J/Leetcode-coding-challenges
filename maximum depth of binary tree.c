/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int result;
void height(struct TreeNode* root, int length){
    if(root==NULL) return;
    if(result<length){
        result=length;
    }
    height(root->left,length+1);
    height(root->right, length+1);
}
int maxDepth(struct TreeNode* root) {
    if(root==NULL) return 0;
    result = 0;
    height(root, 1);
    return result;
}
