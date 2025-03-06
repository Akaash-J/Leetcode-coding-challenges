#define maxx(a,b) ((a)>(b)?(a):(b))
#define minn(a,b) ((a)<(b)?(a):(b))
int maxSubarraySumCircular(int* nums, int numsSize) {
    int max=INT_MIN, Totsum=0, currMax=0, currMin=0, min=INT_MAX;
    
    for(int i=0; i<numsSize; i++){
        Totsum+=nums[i];
        
        currMax = maxx(nums[i], currMax+nums[i]);
        max = maxx(currMax, max);

        currMin = minn(nums[i], currMin+nums[i]);
        min = minn(currMin, min);

    }
    if(max<0){
        return max;
    }
    return maxx(max, Totsum-min);
}
