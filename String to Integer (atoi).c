int myAtoi(char* s) {
    long rev=0;
    int i=0, sign=1;
    while(s[i]==' '){
        i++;
    }
    if(s[i]=='+' || s[i]=='-'){
        sign = (s[i]=='+')?1:-1;
        i++;
    }
    while(s[i]>='0' && s[i]<='9'){
        rev = rev*10 + (s[i]-'0');

        if(rev*sign>=INT_MAX) return INT_MAX;
        if(rev*sign<=INT_MIN) return INT_MIN;
        i++;
    }
    return (int)rev*sign;   
}
