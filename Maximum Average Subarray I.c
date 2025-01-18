double findMaxAverage(int* nums, int numsSize, int k) {
    int l=0, r=0, sum =0, max=INT_MIN;
    for(int i=0; i<numsSize; i++){
        sum = sum+nums[i];
        if(r-l+1==k){
            if(max<sum){
                max=sum;
            }
            sum-=nums[l];
            l++;
        }
        r++;
    }
    return (double)max/k;
}
