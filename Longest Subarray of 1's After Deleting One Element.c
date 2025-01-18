int longestSubarray(int* nums, int numsSize) {
    int l=0, r, zeros=0, max=0;
    for(r=0; r<numsSize; r++){
        if(nums[r]==0) zeros++;
        while(zeros>1){
            if(nums[l]==0){
                zeros--;
            }l++;
        }
        if(max<r-l){
            max = r-l;
        }
    }
    return max;
}
