/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void recursion(int n, int open, int close, char *temp, int index, char **result, int *count){
    if(index==2*n){
        temp[index] = '\0';
        result[*count] = strdup(temp);
        (*count)++;
        return;
    }

    if(open<n){
        temp[index] = '(';
        recursion(n,open+1,close,temp,index+1,result,count);
    }
    if(close<open){
        temp[index] = ')';
        recursion(n,open,close+1,temp, index+1, result, count);
    }
}
char** generateParenthesis(int n, int* returnSize) {
    int maxSize = 1;
    for(int i=n*2; i>n; i--) maxSize*=i;
    for(int i=n; i>1; i--) maxSize/=i;
    char **result = (char**)malloc(maxSize*sizeof(char*));
    char *temp = (char*)malloc((2*n+1)*sizeof(char));
    int count=0;
    recursion(n,0,0,temp,0,result,&count);
    *returnSize = count;
    free(temp);
    return result;

}
