/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int ans=0;
void dfs(struct TreeNode* root, int count, int prevmove){
    if(root==NULL) return;
    if(ans<count){
        ans=count;
    }
    if(prevmove=='l'){
        dfs(root->left,1,'l');
        dfs(root->right,count+1,'r');
    }else{
        dfs(root->left,count+1,'l');
        dfs(root->right,1,'r');
    }
}
int longestZigZag(struct TreeNode* root) {
    int count=0;
    ans = 0;
    char prevmove = 'l';
    dfs(root->left,1,'l');
    dfs(root->right,1,'r');
    return ans;
}
