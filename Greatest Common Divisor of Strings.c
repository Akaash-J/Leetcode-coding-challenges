int gcd(int a, int b){
    while(b!=0){
        int temp = b;
        b=a%b;
        a=temp;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);int len2 = strlen(str2);
    char combined1[len1+len2+1];
    char combined2[len1+len2+1];
    snprintf(combined1, sizeof(combined1), "%s%s", str1,str2);
    snprintf(combined2, sizeof(combined2), "%s%s", str2,str1);
    if(strcmp(combined1,combined2)!=0){
        return "";
    }
    int gcdlength = gcd(len1,len2);
    char *result = (char*)malloc((gcdlength+1)*sizeof(char));
    strncpy(result,str1,gcdlength);
    result[gcdlength]='\0';
    return result;
}
