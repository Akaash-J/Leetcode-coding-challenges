/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    
    qsort(potions, potionsSize, sizeof(int), compare);
    int *result = (int*)malloc(spellsSize*sizeof(int));
    *returnSize = spellsSize;
    for(int i=0; i<spellsSize; i++){
        int l = 0, r=potionsSize-1, mid, temp = potionsSize;
        while(l<=r){
            mid = l+(r-l)/2;
            if(potions[mid]*(long long)spells[i]>=success){
                temp = mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        result[i]=potionsSize-temp;
    }
    return result;
}
