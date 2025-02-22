int search(int* nums, int numsSize, int target) {
    if(numsSize==0) return -1;
    if(numsSize==1 && target==nums[0]) return 0;
    int l=0, r=numsSize-1, mid;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[l]<=nums[mid]){
            if(nums[l]<=target && target<=nums[mid]){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }else{
            if(nums[r]>=target && target>=nums[mid]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
    }
    return -1;
}
