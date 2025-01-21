int firstMissingPositive(int* nums, int numsSize) {
    for(int i=0; i<numsSize; i++){
        if(nums[i]<=0){
            nums[i]=numsSize+1;
        }
    }
    for(int i=0; i<numsSize; i++){
        
        int curr = abs(nums[i]);
        if(curr<=numsSize){
            nums[curr-1] = -abs(nums[curr-1]);
        }
    }
    
    for(int i=0; i<numsSize; i++){
        if(nums[i]>0 ){
            return i+1;
        }
    }
    return numsSize+1;
}
