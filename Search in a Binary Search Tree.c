struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root != NULL && root->val != val) {
        if (val < root->val) {
            root = root->left; // Go to the left subtree
        } else {
            root = root->right; // Go to the right subtree
        }
    }
    return root; // Either the node with val or NULL
}
