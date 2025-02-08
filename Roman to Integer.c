int romanToInt(char* s) {
    int values[26];
    values['I' - 'A'] = 1;
    values['V' - 'A'] = 5;
    values['X' - 'A'] = 10;
    values['L' - 'A'] = 50;
    values['C' - 'A'] = 100;
    values['D' - 'A'] = 500;
    values['M' - 'A'] = 1000;
    int result=0;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i+1]!='\0' && values[s[i]-'A']<values[s[i+1]-'A']){
            result-=values[s[i]-'A'];
        }else{
            result+=values[s[i]-'A'];
        }
    }
    return result;
}
