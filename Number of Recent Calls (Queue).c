


typedef struct {
    int *requests;
    int size;
    int capacity;
    int front;
    int rear;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->capacity = 10000;
    obj->requests = (int*)malloc(obj->capacity*sizeof(int));
    obj->size = 0;
    obj->front = 0;
    obj->rear = -1;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->rear =  (obj->rear + 1)% obj->capacity;
    obj->requests[obj->rear] = t;
    obj->size++;

    while(obj->requests[obj->front] < t-3000){
        obj->front = (obj->front+1) % obj->capacity;
        obj->size--;
    }
    return obj->size;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->requests);
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/
