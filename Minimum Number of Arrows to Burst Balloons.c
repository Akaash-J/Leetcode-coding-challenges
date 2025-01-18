int compare(const void *a, const void *b){
    int *intervala = *(int**)a;
    int *intervalb = *(int**)b;
    if (intervala[1] < intervalb[1]) return -1;
    if (intervala[1] > intervalb[1]) return 1;
    return 0;  
}
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if(pointsSize==0) return 0;
    qsort(points, pointsSize, sizeof(int*), compare);
    int arrows = 1;
    int end = points[0][1];
    for(int i=1; i<pointsSize; i++){
        if(points[i][0]>end){
            arrows++;
            end = points[i][1];
        }
    }
    return arrows;
}
