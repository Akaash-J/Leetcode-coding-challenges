char* convert(char* s, int numRows) {
    if (numRows == 1) return strdup(s);  

    int len = strlen(s);
    char* rows[numRows];
    for(int i=0; i<numRows; i++){
        rows[i] = (char*)malloc(len+1);
        rows[i][0] = '\0';
    }
    int row = 0, step=1;
    for(int i=0; i<len; i++){
        char temp[2] = {s[i],'\0'};
        strcat(rows[row],temp);

        if(row==0) step=1;
        if(row==numRows-1) step=-1;
        row+=step;
    }
    char *result = (char*)malloc(len+1);
    result[0] = '\0';
    for(int i=0; i<numRows; i++){
        strcat(result, rows[i]);
        free(rows[i]);
    }
    return result;
}
