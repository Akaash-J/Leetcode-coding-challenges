/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int k, int n, int start, int *current, int currentsize, int **result, int *returnSize, int**columnsizes){
    if(n==0 && currentsize == k){
    result[*returnSize] = (int*)malloc(currentsize*sizeof(int));
    memcpy(result[*returnSize], current, currentsize*sizeof(int));
    (*columnsizes)[*returnSize] = currentsize;
    (*returnSize)++;
    return;
    }
    if(n<0 || currentsize==k){
        return;
    }
    for(int i=start; i<=9; i++){
        current[currentsize] = i;
        backtrack(k, n-i, i+1, current, currentsize+1, result, returnSize, columnsizes);
    }
}
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int maxCombinations = 1;
    for(int i=0; i<k; i++){
        maxCombinations*= 9-i;
        maxCombinations/= i+1;
    }
    int **result = (int**)malloc(maxCombinations*sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxCombinations*sizeof(int));
    int* current = (int*)malloc(k*sizeof(int));
    backtrack(k,n,1,current,0,result, returnSize, returnColumnSizes);
    free(current);
    return result;
}
