int removeDuplicates(int* nums, int numsSize) {
    int k=1, count=0;
    for(int i=0; i<numsSize; i++){
       if(nums[i]!=nums[k-1]){
            nums[k++]=nums[i];
       }
    }
    return k;
}
