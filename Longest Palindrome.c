int longestPalindrome(char* s) {
    int count[128]= {0}, flag=0,length=0;
    for(int i=0; i<strlen(s); i++){
        count[s[i]]++;
    }
    for(int i=0; i<128; i++){
        if(count[i]%2==0){
            length+=count[i];
        }else{
            length+=count[i]-1;
            flag = 1;
        }
    }
    return length+flag;
}
