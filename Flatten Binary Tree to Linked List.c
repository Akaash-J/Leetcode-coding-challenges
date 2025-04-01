/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* prev = NULL;

void flatten(struct TreeNode* root) {
    if(root==NULL ){
        return;
    }
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;
    if(prev!=NULL){
        prev->right = root;
        prev->left = NULL;
    }
    prev = root;
    flatten(left);
    flatten(right);
}
