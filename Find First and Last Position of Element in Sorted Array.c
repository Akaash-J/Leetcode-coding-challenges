/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int findFirst(int nums[], int l, int h, int target){
    if(l>h) return -1;
    int mid = l+(h-l)/2;
    if((mid==0 || nums[mid-1]<target) && nums[mid]==target){
        return mid;
    }else if(nums[mid]<target){
        return findFirst(nums,mid+1,h,target);
    }else{
        return findFirst(nums, l,mid-1,target);
    }
}

int findLast(int nums[], int l, int h, int target,int n){
    if(l>h) return -1;
    int mid = l+(h-l)/2;
    if((mid==n-1 || nums[mid+1]>target) && nums[mid]==target){
        return mid;
    }else if(nums[mid]>target){
        return findLast(nums, l,mid-1,target,n);
    }else{
        return findLast(nums,mid+1,h,target,n);
    }
}


int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int first = findFirst(nums,0,numsSize-1,target);
    int last = findLast(nums, 0, numsSize-1, target, numsSize);
    int *arr = (int*)malloc(2*sizeof(int));
    arr[0] = first;
    arr[1] = last;
    *returnSize = 2;
    return arr;
}
