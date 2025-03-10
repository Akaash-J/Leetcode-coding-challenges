/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int colSize=*matrixColSize;
    *returnSize = matrixSize*colSize;
    int *result = (int*)malloc((*returnSize)*sizeof(int));
    int top=0,bottom=matrixSize-1, left=0, right=colSize-1, k=0;
    while(top<=bottom && left<=right){
        for(int i=left; i<=right; i++){
            result[k++]=matrix[top][i];
        }
        top++;
        for(int i=top; i<=bottom; i++){
            result[k++]=matrix[i][right];
        }
        right--;
        if(top<=bottom){
            for(int i=right; i>=left; i--){
                result[k++]=matrix[bottom][i];
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom; i>=top; i--){
                result[k++]=matrix[i][left];
            }
            left++;
        }
    }
    return result;
}
