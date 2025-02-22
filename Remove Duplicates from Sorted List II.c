/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL) return head;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* temp = head;
    while(temp!=NULL){
        int dup = 0;
            while(temp->next!=NULL && temp->val==temp->next->val){
                temp=temp->next;
                dup=1;
            }
            if(dup){
                prev->next=temp->next;
            }else{
                prev = prev->next;
            }
            temp=temp->next;
    }
    head = dummy->next;
    free(dummy);
    return head;   
}
