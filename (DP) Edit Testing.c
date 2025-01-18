#define min(a,b,c) ((a)<(b)?((a)<(c)?(a):(c)): ((b)<(c)?(b):(c)))

int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1), len2 = strlen(word2);
    int grid[len1+1][len2+1];
    for(int i=0; i<=len1; i++){
        for(int j=0; j<=len2; j++){
            if(i==0 && j==0){
                grid[i][j]=0;
            }else if(i==0){
                grid[i][j]=grid[i][j-1]+1;
            }else if(j==0){
                grid[i][j] = grid[i-1][j]+1;
            }else{
                if(word1[i-1]!=word2[j-1]){
                    grid[i][j] = 1+ min(grid[i-1][j-1], grid[i][j-1], grid[i-1][j]);
                }else{
                    grid[i][j] = grid[i-1][j-1];
                }
            }
        }
    }
    return grid[len1][len2];
}
