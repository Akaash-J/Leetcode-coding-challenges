#define max(a,b) ((a)>(b)?(a):(b))
int candy(int* ratings, int ratingsSize) {
    int count[ratingsSize];
    for(int i=0; i<ratingsSize; i++){
        count[i] = 1;
    }
    for(int i=1; i<ratingsSize; i++){
        if(ratings[i]>ratings[i-1]){
            count[i] = count[i-1]+1;
        }
    }
    for(int i=ratingsSize-2; i>=0; i--){
        if(ratings[i]>ratings[i+1]){
            count[i]=max(count[i+1]+1, count[i]);
        }
    }
    int c=0;
    for(int i=0; i<ratingsSize; i++){
        c+=count[i];
    }
    return c;
}
