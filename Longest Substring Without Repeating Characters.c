#define max(a, b) ((a) > (b) ? (a) : (b))
int lengthOfLongestSubstring(char* s) {
    int i=0,len=strlen(s), size=0, count[256]={0};
    for(int j=0; j<len; j++){
        count[(unsigned char)s[j]]++;

        while(count[(unsigned char)s[j]]>1){
            count[(unsigned char)s[i]]--;
            i++;
        }
        size = max(size, j-i+1);
    }
    return size;
}
