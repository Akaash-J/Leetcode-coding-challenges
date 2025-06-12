int firstUniqChar(char* s) {
    int freq[26]={0};
    int queue[10000000];
    int front=0, rear=-1;
    for(int i=0; s[i]!='\0'; i++){
        freq[s[i]-'a']++;
        queue[++rear] = i;
        while(front<=rear && freq[s[queue[front]]-'a']>1){
            front++;
        }
        
    }
    if(front>rear) return -1;
        return queue[front];
}
