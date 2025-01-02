
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int pre=1,post=1;
    int *result = (int*)malloc((numsSize+1)*sizeof(int));
    for(int i=0; i<numsSize; i++){
        result[i]=1;
    }
    
    for(int i=0; i<numsSize; i++){
        result[i]*=pre;
        pre*=nums[i];
    }
    for(int i=numsSize-1; i>=0; i--){
        result[i]*=post;
        post*=nums[i];
    }
    
    return result;
}
