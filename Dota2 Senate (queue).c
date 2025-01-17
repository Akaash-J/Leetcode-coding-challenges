# define MAX_SIZE 10000

char* predictPartyVictory(char* senate) {
    int n= strlen(senate);
    int radiantqueue[MAX_SIZE], direqueue[MAX_SIZE];
    int radiantfront = 0, radiantrear = 0;
    int direfront = 0, direrear = 0;
    for(int i=0; i<n; i++){
        if(senate[i]=='R'){
            radiantqueue[radiantrear++] = i;
        }else{
            direqueue[direrear++] = i; 
        }
    }
    while(radiantfront<radiantrear && direfront<direrear){
        int radiantindex = radiantqueue[radiantfront++];
        int direindex = direqueue[direfront++];
        if(radiantindex < direindex){
            radiantqueue[radiantrear++]=radiantindex + n;
        }else{
            direqueue[direrear++] = direindex + n;
        }
    }

    if(radiantfront<radiantrear){
        return "Radiant";
    }
    return "Dire";
}
