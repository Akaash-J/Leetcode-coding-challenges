int findPeakElement(int* nums, int numsSize) {
    int max=nums[0],index=0;
    for(int i=0; i<numsSize; i++){
        if(max<nums[i]){
            max=nums[i];
            index = i;
        }
    }
    return index;
}
