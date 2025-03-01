int mySqrt(int x) {
    if(x==0) return 0;
    int left=1, right = x, ans;
    while(left<=right){
        int mid = left+(right-left)/2;
        long long square = (long long)mid*mid;
        if(square>x){
            right = mid-1;
        }else{
            ans = mid;
            left = mid+1;
        }
    }
    return ans;
}
