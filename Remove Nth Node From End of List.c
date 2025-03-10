/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* slow = dummy;
    struct ListNode* fast = head;
    for(int i=0; i<n; i++){
        fast = fast->next;
    }
    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    struct ListNode* temp = slow->next;
    slow->next = temp->next;
    free(temp);
    head = dummy->next;
    free(dummy);
    return head;
}
