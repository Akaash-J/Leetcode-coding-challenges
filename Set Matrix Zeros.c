void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int col = 1;
    int colSize = *matrixColSize;
    
    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<colSize; j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                if(j!=0){
                    matrix[0][j]=0;
                }else{
                    col=0;
                }
            }
                
        }
    }
    
    for(int i=1; i<matrixSize; i++){
        for(int j=1; j<colSize; j++){
            if(matrix[i][j]!=0){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
            }
        }
    }
    if(matrix[0][0]==0){
        for(int j=0; j<colSize; j++){
            matrix[0][j]=0;
        }
    }
    if(col==0){
        for(int i=0; i<matrixSize; i++){
            matrix[i][0]=0;
        }
    }
    
    for(int i=0; i<matrixSize;i++){
        for(int j=0; j<colSize;j++){
            printf("%d ",matrix[i][j]);
        }
    }
}
