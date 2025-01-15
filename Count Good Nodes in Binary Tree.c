/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int count(struct TreeNode* node, int maxpath){
    if(node==NULL) return 0;
    int isgood = 0;
    if(node->val>=maxpath){
        isgood=1;
        maxpath = node->val;
    }
    return isgood + count(node->left, maxpath) + count(node->right, maxpath);
}

int goodNodes(struct TreeNode* root){
 return count(root, INT_MIN);
}
