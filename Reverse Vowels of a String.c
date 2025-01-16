#define isvowel(ch) ((ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')? 1: 0)
char* reverseVowels(char* s) {
    int len = strlen(s);
    int l=0, h=len-1;
    while(l<h){
        if(isvowel(s[l]) && isvowel(s[h])){
            char temp = s[l];
            s[l]=s[h];
            s[h]=temp;
            l++; h--;
        }else if(isvowel(s[l])){
            h--;
        }else{
            l++;
        }
    }
    return s;
}
