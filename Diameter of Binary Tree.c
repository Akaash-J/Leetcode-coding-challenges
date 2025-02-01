/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max(a,b)((a)>(b)?(a):(b))
int helper(struct TreeNode* root, int *diameter){
    if(root == NULL) return 0;
    int leftHeight = helper(root->left,diameter);
    int rightHeight = helper(root->right, diameter);
    *diameter = max(*diameter, leftHeight+rightHeight);
    return max(leftHeight,rightHeight)+1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    helper(root, &diameter);

    return diameter;
}
