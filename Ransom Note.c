bool canConstruct(char* ransomNote, char* magazine) {
    int count[26]={0};
    for(int i=0; i<strlen(magazine); i++){
        count[(int)magazine[i]-'a']++;
    }
    for(int i=0; ransomNote[i]!='\0'; i++){
        if(count[(int)ransomNote[i]-'a']>0){
            count[(int)ransomNote[i]-'a']--;
        }else{
            return false;
        }
    }
    return true;
}
