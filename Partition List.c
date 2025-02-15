/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if(head==NULL) return head;
    struct ListNode small_dummy = {0,NULL};
    struct ListNode high_dummy = {0,NULL};
    struct ListNode* small = &small_dummy;
    struct ListNode* high = &high_dummy;
    while(head!=NULL){
        if(head->val<x){
            small->next = head;
            small = small->next;
        }else{
            high->next = head;
            high = high->next;
        }
        head=head->next;
    }
    small->next = high_dummy.next;
    high->next = NULL;
    head = small_dummy.next;
    return head;
}
