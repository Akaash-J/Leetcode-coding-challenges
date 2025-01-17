int pivotIndex(int* nums, int numsSize) {
    int right = 0, left = 0;
    for(int i=0; i<numsSize; i++){
        right+=nums[i];
    }
    int i;
    for(i=0; i<numsSize; i++){
        right=right-nums[i];
        if(left==right){
            return i;
        }
            left+=nums[i];
    }
    return -1;
}
