/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b){
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if(intervalsSize==0){
        *returnSize = 0;
        *returnColumnSizes = 0;
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    int **result = (int**)malloc(intervalsSize*sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    *returnSize=0;
    int start = intervals[0][0], end = intervals[0][1];
    for(int i=0 ;i<intervalsSize; i++){
        if(intervals[i][0]<=end){
            end = (intervals[i][1]>end)?intervals[i][1]:end;
        }
        else{
            result[*returnSize] = (int*)malloc(2*sizeof(int));
            result[*returnSize][0] = start;
            result[*returnSize][1] = end;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    result[*returnSize] = (int*)malloc(2*sizeof(int));
    result[*returnSize][0] = start;
    result[*returnSize][1] = end;
    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;
            
    return result;
}
