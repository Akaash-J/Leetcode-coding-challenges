


typedef struct {
    int stack[10000][2];
    int top;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner));
    obj->top = -1;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;
    while(obj->top>=0 && obj->stack[obj->top][0]<=price){
        span += obj->stack[obj->top--][1];
    }
    obj->stack[++obj->top][0] = price;
    obj->stack[obj->top][1] = span;
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/
