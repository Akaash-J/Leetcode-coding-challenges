
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *result = (int*)malloc(nums2Size*sizeof(int));
    int *stack = (int*)malloc(nums2Size*sizeof(int));
    int top=-1;
    for(int i=nums2Size-1; i>=0; i--){
        while(top!=-1 && stack[top]<=nums2[i]) top--;

        if(top==-1){
            result[i] = -1;
        }else{
            result[i] = stack[top];
        }
        stack[++top] = nums2[i];
    }
    int *r = (int*)malloc(nums1Size*sizeof(int));
    for(int i=0; i<nums1Size; i++){
        for(int j=0; j<nums2Size; j++){
            if(nums1[i]==nums2[j]){
                r[i] = result[j];
                break;
            }
        }
    }
    free(stack);
    free(result);
    *returnSize = nums1Size;
    return r;
}
