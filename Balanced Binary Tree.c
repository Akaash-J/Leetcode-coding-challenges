/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max(a,b) ((a)>(b)?(a):(b))
int height(struct TreeNode* root){
    if(root==NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight)+1;
}

bool isBalanced(struct TreeNode* root) {
    if(root==NULL) return true;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (abs(leftHeight-rightHeight)<=1) && isBalanced(root->left) && isBalanced(root->right);
}
