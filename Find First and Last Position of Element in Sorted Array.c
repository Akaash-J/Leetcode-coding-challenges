/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *arr = (int*)malloc(2*sizeof(int));
    arr[0] = -1;
    arr[1] = -1;
    if(numsSize==0)  return arr;
    int left = 0, right = numsSize-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(nums[mid]>=target){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    if(left>=numsSize || nums[left]!=target) return arr;
    arr[0] = left;
    right = numsSize-1;
    while(left<=right){
        int mid = left +(right-left)/2;
        if(nums[mid]<=target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    arr[1] = right;
    return arr;
}
