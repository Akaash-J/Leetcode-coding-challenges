/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int* l, int* r){
    int temp;
    temp = *l;
    *l = *r;
    *r = temp;
}
void backtrack(int** result,int *returnSize, int *temp,int* nums,int numsSize, int l, int r){
    if(l==r){
        result[(*returnSize)] = (int*)malloc(numsSize * sizeof(int));
        memcpy(result[*returnSize], nums, numsSize * sizeof(int)); 
        (*returnSize)++;
        return;

    }
        for(int i=l; i<=r; i++){
            swap(&nums[l],&nums[i]);
            backtrack(result,returnSize,temp,nums,numsSize,l+1,r);
            swap(&nums[l],&nums[i]);
        }
    
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalPermutations = 1;
    for(int i=2; i<=numsSize; i++){
        totalPermutations*=i;
    }
    *returnColumnSizes = (int*)malloc(totalPermutations*sizeof(int));
    int **result = (int**)malloc(totalPermutations*sizeof(int*));
    *returnSize = 0;
    int *temp = (int*)malloc(numsSize*sizeof(int));
    backtrack(result,returnSize,temp,nums,numsSize,0,numsSize-1);
    free(temp);
    for(int i=0; i<*returnSize; i++){
        (*returnColumnSizes)[i] = numsSize;
    }
    return result;
}
