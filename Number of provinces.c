void dfs(int** isConnected, int n, int* visited, int i){
    visited[i]=1;
    for(int j=0; j<n; j++){
        if(isConnected[i][j]==1 && !visited[j]){
            dfs(isConnected, n, visited, j);
        }
    }
}
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int visited[n];
    memset(visited,0,sizeof(visited));
    int count=0;
    for(int i=0; i<n; i++){
        if(visited[i]==0){
            count++;
            dfs(isConnected,n,visited,i);
        }
    }
    return count;
}
