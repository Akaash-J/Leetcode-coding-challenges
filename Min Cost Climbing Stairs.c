int minCostClimbingStairs(int* cost, int costSize) {
    int min[costSize+1]; min[0] = 0;
    min[1]=0;
    for(int i=2; i<costSize+1; i++){
        if(cost[i-2]+min[i-2] > cost[i-1]+min[i-1]){
            min[i] = cost[i-1]+min[i-1];
        }else{
            min[i] = cost[i-2]+min[i-2];
        }
    }
    return min[costSize];
}
