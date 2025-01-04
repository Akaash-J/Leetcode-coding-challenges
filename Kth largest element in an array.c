void heapify(int heap[], int k, int i){
    int smallest =i; 
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<k && heap[smallest]>heap[left]){
        smallest=left;
    }
    if(right<k && heap[smallest]>heap[right]){
        smallest=right;
    }
    if(smallest != i){
        int temp = heap[i];
        heap[i]=heap[smallest];
        heap[smallest] = temp;
        heapify(heap, k, smallest);
    }
}
int findKthLargest(int* nums, int numsSize, int k) {
    int heap[k];
    for(int i=0; i<k; i++){
        heap[i]=nums[i];
    }
    for(int i=k/2-1; i>=0; i--){
        heapify(heap,k,i);
    }
    for(int i=k; i<numsSize; i++){
        if(nums[i]>heap[0]){
            heap[0]=nums[i];
            heapify(heap,k,0);
        }
    }
    return heap[0];
}
