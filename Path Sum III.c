/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int f1(struct TreeNode* node, long long sum){
    if(node==NULL) return 0;
    int count=0;
    if(node->val == sum){
        count=1;
    }
    long long newsum = sum - node->val;
    count+=f1(node->left, newsum);
    count+=f1(node->right, newsum);
    return count;

}
int pathSum(struct TreeNode* root, long long targetSum) {
    if(root==NULL) return 0;
    return pathSum(root->left, targetSum)+pathSum(root->right, targetSum)+ f1(root, targetSum); 
}
