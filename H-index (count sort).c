int hIndex(int* citations, int citationsSize) {
    if(citationsSize==0) return 0;
    int min = citations[0],max=citations[0];
    for(int i=0; i<citationsSize; i++){
        if(min>citations[i]){
            min=citations[i];
        }
        if(max<citations[i]){
            max=citations[i];
        }
    }
    int range = max-min+1;
    int *count = (int*)calloc(range, sizeof(int));
    for(int i=0; i<citationsSize; i++){
        count[citations[i]-min]++;
    }
    int index=0;
    for(int i=0; i<range; i++){
        while(count[i]>0){
            citations[index++]=i+min;
            count[i]--;
        }
    }
    free(count);
    int h;
    
    for(int i=0; i<citationsSize; i++){
        if(citations[i]>=(citationsSize-i)){
            return citationsSize-i;
        }
    }
    return 0;
}
