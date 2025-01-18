# define max(a,b) ((a)<(b)?(b):(a))
int rob(int* nums, int numsSize) {
    if(numsSize==1){
        return nums[0];
    }
    nums[1] = max(nums[1],nums[0]);
    for(int i=2; i<numsSize; i++){
        nums[i] = max(nums[i]+nums[i-2], nums[i-1]);
        
    }
    return nums[numsSize-1];

}
