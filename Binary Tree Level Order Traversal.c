/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(root==NULL){
        *returnSize =0;
        *returnColumnSizes = NULL;
        return NULL;
    }
     int capacity = 1000;  
    int **result = (int**)malloc(1000*sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000*sizeof(int));
    *returnSize = 0;
    struct TreeNode* temp;
    struct TreeNode* queue[10000];
    int front = 0, rear =0;
    queue[rear++] = root;
    while(front!=rear){
        int levelSize = rear-front;
         if (*returnSize >= capacity) {
            capacity *= 2;
            result = (int**)realloc(result, capacity * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
        }
        result[*returnSize] = (int*)malloc(levelSize*sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;
        for(int i=0; i<levelSize; i++){
            temp = queue[front++];
            result[*returnSize][i] = temp->val;

           if(temp->left) queue[rear++] = temp->left;
           if(temp->right) queue[rear++] = temp->right;
        }
        (*returnSize)++;
    }
    return result;
}
