void reverse(char *s, int i, int k){
    while(i<k){
        char temp = s[i];
        s[i] = s[k];
        s[k] = temp;
        i++; k--;
    }
}
char* reverseStr(char* s, int k) {
    int n = strlen(s);
    for(int i=0; i<n; i+=2*k){
        int end = (i+k-1<n)?(i+k-1):n-1;
        reverse(s,i,end);
    }
    return s;
}
