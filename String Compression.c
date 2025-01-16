int compress(char* chars, int charsSize) {
    char ptr = chars[0];
    int run = 0; int j=0;
    for(int i=0; i<charsSize; i++){
        if(ptr==chars[i]){
            run++;
        }else{
            chars[j++] = ptr;
            if(run>1){
                char countstr[10];
                int countlen = sprintf(countstr, "%d", run);
                for(int k=0; k<countlen; k++){
                    chars[j++] = countstr[k];
                }
            }
            run=1;
            ptr = chars[i];
        }
    }
            chars[j++] = ptr;
            if(run>1){
                char countstr[10];
                int countlen = sprintf(countstr, "%d", run);
                for(int k=0; k<countlen; k++){
                    chars[j++] = countstr[k];
                }
            }
            return j;
}
