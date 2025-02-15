/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL || head->next==NULL || k==0) return head;
    struct ListNode* temp = head;
    int count=1;
    while(temp->next){
        temp=temp->next;
        count++;
    }
    temp->next = head;
    k = k%count;
    if(k==0){
        temp->next = NULL;
        return head;
    }
    temp = head;
    int len = count-k;
    for(int i=1; i<len; i++){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    
    return head;
    
}
