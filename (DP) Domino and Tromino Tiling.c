#define MOD 1000000007
int numTilings(int n) {
int arr[1001];
    arr[0] =0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 5;
    if(n<=3){
        return arr[n];
    } 
    for(int i=4; i<=n; i++){
        arr[i] = (2*arr[i-1])% MOD;
        arr[i] = (arr[i] + arr[i-3])%MOD;
    }
    
    return arr[n];;
}