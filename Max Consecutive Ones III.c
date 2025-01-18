#define max(a,b) ((a)>(b)?(a):(b))
int longestOnes(int* nums, int numsSize, int k) {
    int l=0, maxcount=0, zeros =0 ;
    for(int r=0; r<numsSize; r++){
        if(nums[r]==0) zeros++;
        while(zeros>k){
            if(nums[l]==0){
                zeros--;
            }l++;
        }
        maxcount = max(maxcount,r-l+1);
    }
    return maxcount;
}
