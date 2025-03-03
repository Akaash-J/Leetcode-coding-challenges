bool isIsomorphic(char* s, char* t) {
    char map_s[256] = {0};
    char map_t[256] = {0};
    for(int i=0; i<strlen(t); i++){
        if(map_s[(unsigned char)s[i]]==0 && map_t[(unsigned char)t[i]]==0){
            map_s[(unsigned char)s[i]] = t[i];
            map_t[(unsigned char)t[i]] = s[i];
        }else if(map_s[(unsigned char)s[i]]!=t[i] || map_t[(unsigned char)t[i]]!=s[i]){
            return false;
        }
    }
    return true;
}
