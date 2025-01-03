/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void mergesort(int *nums, int l, int r);

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    mergesort(nums,0,numsSize-1);
    return nums;
}

void mergesort(int *nums, int l, int r){
    if(l>=r){
        return;
    }
    int m = l+(r-l)/2;
    mergesort(nums,l,m);
    mergesort(nums,m+1,r);
    int lstart = l;
    int rstart = m+1;
    int lsize = m-l+1;
    int rsize = r-m;
    int lhalf[m-l+1];
    int rhalf[r-m];
    for(int i=0; i<m-l+1; i++){
        lhalf[i] = nums[lstart+i];
    }
    for(int i=0; i<r-m; i++){
        rhalf[i] = nums[rstart+i];
    }
    int p1=0, p2=0, i=l;
    while(p1<m-l+1 && p2<r-m){
        if(lhalf[p1]<=rhalf[p2]){
            nums[i++]=lhalf[p1++];
        }
        else{
            nums[i++]=rhalf[p2++];
        }
    }
    while(p1<m-l+1){
            nums[i++]=lhalf[p1++];
    }
     while(p2<r-m){
            nums[i++]=rhalf[p2++];
    }
}
