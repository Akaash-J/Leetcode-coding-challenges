#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int trap(int* height, int heightSize) {
    if(heightSize<3) return 0;

    int leftmax = height[0];
    int stack[heightSize];
    
    stack[heightSize-1] = height[heightSize-1];
    for(int i=heightSize-2; i>=0; i--){
        stack[i] = max(height[i],stack[i+1]);
    }
    int totwater = 0;
    for(int i=1; i<heightSize-1; i++){
        
        int minimum = min(leftmax,stack[i]);
        if(minimum>height[i]){
            totwater+=minimum - height[i];
        }
       
        leftmax = max(leftmax,height[i]);
    }
    return totwater;
}
