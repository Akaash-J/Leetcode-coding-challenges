int longestPalindromeSubseq(char* s) {
    char t[1001];
    strcpy(t,s);
    int len = strlen(s);
    int start=0, end=len-1;
    while(start<end){
        char temp = t[start];
        t[start] = t[end];
        t[end] = temp;
        start++;
        end--;
    }
    int dp[1001][1001]={0};
    
    for(int i=1; i<=len; i++){
        for(int j=1; j<=len; j++){
            if(t[i-1]==s[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j] = (dp[i][j-1]>dp[i-1][j])?dp[i][j-1]:dp[i-1][j];
            }
        }
    }
    return dp[len][len];
}
