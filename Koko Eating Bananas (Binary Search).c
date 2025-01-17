int minEatingSpeed(int* piles, int pilesSize, int h) {
    int max = piles[0];
    for(int i=0; i<pilesSize; i++){
        if(piles[i]>max){
            max = piles[i];
        }
    }
    int l=1, r = max, mid, ans=INT_MAX;
    while(l<=r){
        mid = l+(r-l)/2;
        long long add = 0;
        for(int i=0; i<pilesSize; i++){
            add += (piles[i] + mid-1) / mid;
        }
        if(add>h){
            l = mid+1;
        }else{
            ans = mid;
            r = mid-1;
        }
    }
    return ans;
}
