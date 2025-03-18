bool canJump(int* nums, int numsSize){
    int stepLeft=nums[0];
    for(int i=1; i<numsSize; i++){
        stepLeft--;
        if(stepLeft<0){
            return false;
        }
        if(nums[i]>stepLeft){
            stepLeft = nums[i];
        }
        if(i==numsSize-1) return true;
        
    }
    
    return true;
}
