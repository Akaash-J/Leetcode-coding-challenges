int bs(int arr[], int left, int right, int key){
    while(left<=right){
        int mid = left+(right-left)/2;
        if(arr[mid]>=key){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return left;
}

int lengthOfLIS(int* nums, int numsSize) {
    int length=1, arr[numsSize];
    arr[0]=nums[0];
    for(int i=0; i<numsSize; i++){
        if(nums[i]>arr[length-1]){
            arr[length++]=nums[i];
        }else{
            int pos = bs(arr, 0, length-1, nums[i]);
            arr[pos]= nums[i];
        }
    }
    return length;
}
