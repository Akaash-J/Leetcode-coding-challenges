/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct queueNode{
    struct TreeNode* node;
    int level;
    struct queueNode* next;
};
struct queue{
    struct queueNode* front;
    struct queueNode* rear;
};
struct queueNode* newqueueNode(struct TreeNode* node, int level){
    struct queueNode* newnode = (struct queueNode*)malloc(sizeof(struct queueNode));
    newnode->node = node;
    newnode->level = level;
    newnode->next = NULL;
    return newnode;
}
struct queue* createqueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
void enqueue(struct queue* q, struct TreeNode* node, int level){
    struct queueNode* temp = newqueueNode(node, level);
    if(q->rear == NULL){
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
struct queueNode* dequeue(struct queue* q){
    if(q->front == NULL) return NULL;
    struct queueNode* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL) q->rear=NULL;
    return temp;
}
int isqueueEmpty(struct queue* q){
    return q->front == NULL;
}

int maxLevelSum(struct TreeNode* root) {
    if (!root) return 0;

    // Initialize queue
    struct queue* q = createqueue();
    enqueue(q, root, 1);

    int maxsum = INT_MIN;  // To track maximum sum
    int maxlevel = 0;      // To track the level with max sum

    while (!isqueueEmpty(q)) {
        int currlevel = q->front->level;  // Current level
        int currlvlsum = 0;              // Sum for the current level

        // Process all nodes in the current level
        while (!isqueueEmpty(q) && q->front->level == currlevel) {
            struct queueNode* current = dequeue(q);
            currlvlsum += current->node->val;

            // Enqueue children with their respective levels
            if (current->node->left) {
                enqueue(q, current->node->left, current->level + 1);
            }
            if (current->node->right) {
                enqueue(q, current->node->right, current->level + 1);
            }
            free(current);
        }

        // Update maxsum and maxlevel if necessary
        if (currlvlsum > maxsum) {
            maxsum = currlvlsum;
            maxlevel = currlevel;
        }
    }

    return maxlevel;
}
