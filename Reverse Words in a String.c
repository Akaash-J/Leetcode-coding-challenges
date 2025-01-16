void reverse(char *s, int start, int end){
    char temp;
  while(start<end){
    temp = s[start];
    s[start]=s[end];
    s[end]=temp;
    start++; end--;
  }
}
char* reverseWords(char* s) {
    int n = strlen(s);
    int i=0, j=0;
    int k=0;
    while(i<n){
        while(i<n && s[i]==' ') i++;
        while(i<n && s[i]!=' ') s[k++] = s[i++];
        if(i<n) s[k++]=' ';
    }
    if(k>0 && s[k-1]==' ') k--;
    s[k] = '\0';
    reverse(s,0,k-1);
    for(i=0; i<k; i++){
        if(s[i]!=' '){
            j=i;
            while(j<k && s[j]!=' ') j++;
            reverse(s,i,j-1);
            i=j;
        }
    }
    return s;
}
