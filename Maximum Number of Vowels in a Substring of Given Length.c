#define isvowel(ch) ((ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')?1:0)

int maxVowels(char* s, int k) {
    int count=0, max=INT_MIN, len=strlen(s);
    for(int i=0; i<k; i++){
        if(isvowel(s[i])){
            count++;
        }
    }
    max = count;
    for(int i=k; i<len; i++){
        if(isvowel(s[i])){
            count++;
        }
        if(isvowel(s[i-k])){
            count--;
        }
        if(max<count){
            max = count;
        }
    }
    return max;
}
