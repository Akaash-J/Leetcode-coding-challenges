#define min(a,b) ((a)<(b)?(a):(b))
int minSubArrayLen(int target, int* nums, int numsSize) {
    int i=0, sum=0, minn=INT_MAX;
    for(int j=0; j<numsSize; j++){
        sum+=nums[j];
        while(sum>=target){
            minn = min(minn,j-i+1);
            sum-=nums[i];
            i++;
        }
    }
    return (minn==INT_MAX)?0:minn;
    
}
