#define max(a,b) ((a)>(b) ? (a) : (b))
int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1), n=strlen(text2);
    int grid[m+1][n+1];
    memset(grid, 0, sizeof(grid));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(text1[i-1]==text2[j-1]){
                grid[i][j] = grid[i-1][j-1]+1;
            }else{
                grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
            }
        }
    }
    return grid[m][n];
}
