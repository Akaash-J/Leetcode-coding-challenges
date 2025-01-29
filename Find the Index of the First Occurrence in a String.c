int strStr(char* haystack, char* needle) {
    int i=0,n=strlen(haystack),j=0,m=strlen(needle);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(haystack[i+j]!=needle[j]){
                break;
            }
        }
        if(j==m) return i;
    }
    
    return -1;
}
