char* removeDuplicateLetters(char* s) {
    bool visited[26] = {false};
    int index[26] = {0};
    char* stack = (char*)malloc(strlen(s)*sizeof(char));
    int top=-1;
    for(int i=0; s[i]!='\0'; i++){
        index[s[i]-'a'] = i;
    }
    for(int i=0; s[i]!='\0'; i++){
        if(!visited[s[i]-'a']){
            while(top!=-1 && stack[top]>s[i] && index[stack[top]-'a']>i){
                visited[stack[top]-'a'] = false;
                top--;
            } 
            stack[++top] = s[i];
            visited[s[i]-'a'] = true;
        }
    }
    char* result = (char*)malloc(top + 2);
    for (int i = 0; i <= top; i++) {
        result[i] = stack[i];
    }
    result[top + 1] = '\0';
    return result;
}
