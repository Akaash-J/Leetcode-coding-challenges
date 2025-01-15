/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL){
        return NULL;
    }
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* nex;

    while(curr!=NULL){
        nex= curr->next;
        curr->next = prev;
        if(nex==NULL){
            break;
        }
        prev = curr;
        curr = nex;
    }
    return curr;
}
