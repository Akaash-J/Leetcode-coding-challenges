/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(left==right) return head;

    struct ListNode dummy, *prev, *curr, *next, *temp ;
    dummy.next = head;
    struct ListNode* prevleft = &dummy;
    for(int i=1; i<left; i++){
        prevleft = prevleft->next;
    }
    
    curr = prevleft->next;
    prev = NULL;
    next = NULL;
    for(int i=left; i<=right; i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    prevleft->next->next = curr;
    prevleft->next = prev;
    return dummy.next;
}
