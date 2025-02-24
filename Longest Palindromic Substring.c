int check(char *s, int l, int h){
    while(l>=0 && h<strlen(s) && s[l]==s[h]){
        l--; h++;
    }
    return h-l-1;
}

char* longestPalindrome(char* s) {
    if(s==NULL || s[0]=='\0') return NULL;
    int len = strlen(s), Maxlen = 0,start;
    for(int i=0; i<len; i++){
        int len1 = check(s,i,i);
        int len2 = check(s,i,i+1);
        int lenMax = (len1>len2)?len1:len2;
        if(Maxlen<lenMax){
            Maxlen = lenMax;
            start = i-(lenMax-1)/2;
        } 
    }
    char *result = (char*)malloc((Maxlen+1 )*sizeof(char));
    strncpy(result, s+start, Maxlen);
    result[Maxlen] = '\0';
    return result;
}
