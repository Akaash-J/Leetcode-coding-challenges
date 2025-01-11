/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head==NULL){
        free(head);
        return NULL;
    }
    while(head!=NULL && head->val == val){
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    struct ListNode *slow = NULL;
    struct ListNode *fast = head;

    while(fast!=NULL){
        if(fast->val == val){
            slow->next = fast->next;
            free(fast);
            fast = slow->next;
        }else{
        slow = fast;
        fast = fast->next;
        }
    }
    return head;
}
