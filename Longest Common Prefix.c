char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize==0) return "";
    for(int i=0;strs[0][i]!='\0'; i++){
        for(int j=1; j<strsSize; j++){
            if(strs[j][i]=='\0' || strs[0][i]!=strs[j][i]){
                strs[0][i]='\0';
                return strs[0];
            }
        }   
    }
    return strs[0];
}
