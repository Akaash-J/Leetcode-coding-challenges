
bool rotateString(char* s, char* goal) {
    
    if(strlen(s)!=strlen(goal)) return false;
    int len = strlen(s);
    char newstr[2*len+1];
    strcpy(newstr, s);
    strcat(newstr, s);
    return strstr(newstr,goal)!=NULL;
}
