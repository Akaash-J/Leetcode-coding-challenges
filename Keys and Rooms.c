bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];
    memset(visited,false,sizeof(visited));
    int stack[roomsSize];
    int top=-1;
    stack[++top] = 0;
    visited[0] = true;
    int visitedCount = 1;
    while(top>=0){
        int currentRoom = stack[top--];
        for(int i=0; i<roomsColSize[currentRoom]; i++){
            int nextRoom = rooms[currentRoom][i];
            if(!visited[nextRoom]){
                stack[++top] = nextRoom;
                visited[nextRoom] = true;
                visitedCount++;
            }
        }
    }
    return visitedCount == roomsSize;
}
