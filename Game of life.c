void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int x[8] = {0,1,1,1,0,-1,-1,-1};
    int y[8] = {1,1,0,-1,-1,-1,0,1};
    int colSize = *boardColSize;
    for(int i=0; i<boardSize; i++){
        for(int j=0; j<colSize; j++){
            int one =0, zero=0;
            for(int k=0; k<8; k++){
                int ni = i+x[k], nj = j+y[k];
                if(ni>=0 && ni<boardSize && nj>=0 && nj<colSize){
                    if(board[ni][nj]==1 || board[ni][nj]==3){
                        one++;
                    }else{
                        zero++;
                    }
                }
            }
            if(board[i][j]==1){
                if(one<2 || one>3){
                    board[i][j]=3;
                }
            }else{
                if(one==3){
                    board[i][j]=2;
                }
            }
        }
    }
    for(int i=0; i<boardSize; i++, printf("\n")){
        for(int j=0; j<colSize; j++){
            if(board[i][j]==2){
                board[i][j]=1;
            }else if(board[i][j]==3){
                board[i][j]=0;
            }
        }
    }
    for(int i=0; i<boardSize; i++, printf("\n")){
        for(int j=0; j<colSize; j++){
            printf("%d ",board[i][j]);
        }
    }
}
