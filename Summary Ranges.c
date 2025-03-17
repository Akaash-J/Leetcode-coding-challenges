/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if(numsSize==0){
        *returnSize=0;
        return NULL;
    }

    char **result = (char**)malloc(numsSize*sizeof(char*));
    *returnSize=0;
    int start = 0;
    for(int i=1; i<=numsSize; i++){
        if(i==numsSize || nums[i]!=nums[i-1]+1){
            result[*returnSize] = (char*)malloc(30*sizeof(char));
            if(start==i-1){
                sprintf(result[*returnSize], "%d", nums[start]);
            }else{
                sprintf(result[*returnSize], "%d->%d", nums[start], nums[i-1]);
            }
            (*returnSize)++;
            start = i;
        }
    }
    return result;
}
