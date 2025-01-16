bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    for(int i=0; i<flowerbedSize; i+=2){
        if(flowerbed[i]==0){
            if(i==flowerbedSize-1 || flowerbed[i]==flowerbed[i+1]){
                n--;
            }else{
                i++;
            }
        }
    }
    return n<=0;
}
