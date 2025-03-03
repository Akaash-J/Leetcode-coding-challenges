#define MAX_WORDS_LEN 100
typedef struct{
    char key[100];
    char value[MAX_WORDS_LEN];
}hashMap;

bool wordPattern(char* pattern, char* s) {
    int words=0,ch=0;
    char storage[500][100];
    for(int i=0; i<=strlen(s); i++){
        if(s[i]==' '|| s[i]=='\0'){
            storage[words][ch]='\0';
            words++; ch=0;
        }else{
            storage[words][ch++]=s[i];
        }
    }
    if(strlen(pattern)!=words){
        return false;
    }
    hashMap map[128] = {0};
    char mappedWords[500][100]={0};
    for(int i=0; i<strlen(pattern); i++){
        char ch = pattern[i];
        if(map[ch].key[0]!='\0'){
            if(strcmp(map[ch].value, storage[i])!=0){
                return false;
            }
        }else{
            for(int j=0; j<words; j++){
                if(strcmp(mappedWords[j], storage[i])==0){
                    return false;
                }
            }
            strcpy(map[ch].key, &ch);
            strcpy(map[ch].value,storage[i]);
            strcpy(mappedWords[i],storage[i]);
        }
    }
    return true;
}
