#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int maxProfit(int* prices, int pricesSize, int fee) {
    int profit =0, effbuy;
    effbuy = prices[0];

    for(int i=1; i<pricesSize; i++){
        profit = max(profit, prices[i]-effbuy-fee);
        effbuy = min(effbuy, prices[i]-profit);
    }
    return profit;
}
