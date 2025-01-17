/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *stack;
int top = -1;

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;
    stack = (int*)malloc(temperaturesSize*sizeof(int));
    int *result = (int*)malloc(temperaturesSize*sizeof(int));
    for(int i=0; i<temperaturesSize; i++){
        while(top>=0 && temperatures[stack[top]]<temperatures[i]){
            int idx = stack[top--];
            result[idx] = i-idx;
        }
        stack[++top]=i;
    }
    while(top>=0){
        result[stack[top--]]=0;
    }
    free(stack);
    return result;
}
