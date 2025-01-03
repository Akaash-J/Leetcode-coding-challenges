
int maxOperations(int* nums, int numsSize, int k){
    int count = 0;
    int *freq = (int*)calloc(k,sizeof(int));
    for(int i=0; i<numsSize; i++){
        int diff = k-nums[i];
        if(diff>=0 && diff<k && freq[diff]>0){
            count++;
            freq[diff]--;
        }else{
            if(nums[i]<k){
                freq[nums[i]]++;
            }
        }
    }
    return count;
}
