void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0 || k % numsSize == 0) return;  // Edge case check

    k = k % numsSize;
    int i=0,j=numsSize-k-1;
    while(i<j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++; j--;
    }
    i=numsSize-k; j=numsSize-1;
    while(i<j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++; j--;
    }
    i=0, j=numsSize-1;
    while(i<j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++; j--;
    }
    for(int i=0; i<numsSize; printf("%d ",nums[i++]));
}
