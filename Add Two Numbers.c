/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *res = NULL;
    struct ListNode *current = NULL;
    int sum, carry=0,digit;
    while(l1!=NULL || l2!=NULL){
        int val1 = (l1!=NULL)?l1->val:0;
        int val2 = (l2!=NULL)?l2->val:0;

        sum = val1+val2+carry;
        carry = sum/10;
        digit = sum%10;
        struct ListNode *value = (struct ListNode*)malloc(sizeof(struct ListNode));
        value->val = digit;
        value->next = NULL;
        if(res==NULL){
            res = value;
            current = value;
        }else{
            current->next = value;
            current = value;
        }

        if(l1!=NULL) l1 = l1->next;
        if(l2!=NULL) l2 = l2->next;  
    }
    
    if(carry !=0){
        struct ListNode *value = (struct ListNode*)malloc(sizeof(struct ListNode));
        value->val = carry;
        value->next = NULL;
        current->next = value;
        current = value;
    }
    return res;
}
