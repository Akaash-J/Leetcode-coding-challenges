int squareSum(int n);
bool isHappy(int n) {
    
    while(n!=1 && n!=4){
        n=squareSum(n);
    }
    return (n==1);
}

int squareSum(int n){
    int sum=0;
    while(n>0){
        int l=n%10;
        sum=sum+(l*l);
        n/=10;
    }
    return sum;
}
