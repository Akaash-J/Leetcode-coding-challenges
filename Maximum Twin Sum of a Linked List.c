/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    
    struct ListNode *fast, *slow, *prev, *next;
    fast = head;
    slow= head;
    while(fast!=NULL){
        fast=fast->next->next;
        slow = slow->next;
    }
    prev = NULL;
    while(slow!=NULL){
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    int max = 0;
    while(head!=NULL && prev!=NULL){
        if(head->val+prev->val >max){
            max=head->val+prev->val;
        }
        head = head->next;
        prev = prev->next;
    }
    return max;
}
