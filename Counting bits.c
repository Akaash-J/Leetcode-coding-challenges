/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include<stdlib.h>
int* countBits(int n, int* returnSize) {
    int count=0;
    *returnSize = n+1;
    int* arr = (int*)malloc((*returnSize)*sizeof(int));
    arr[0] = 0;
    for(int i=1; i<=n; i++){
        arr[i] = arr[i >> 1]+ (i & 1);
    }
    return arr;
}
