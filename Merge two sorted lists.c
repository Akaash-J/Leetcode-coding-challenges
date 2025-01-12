/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;

    struct ListNode *curr = NULL;
    struct ListNode *result = NULL;
    while(list1!=NULL && list2!=NULL){
        if(list1->val<=list2->val){
            if(curr==NULL){
                curr = list1;
                result = curr;
            }else{
                curr->next = list1;
                curr = curr->next;
            }
            list1 = list1->next;
        }else{
            if(curr==NULL){
                curr = list2;
                result = curr;
            }else{
                curr->next = list2;
                curr = curr->next;
            }
            list2 = list2->next;
        }
    }
    while(list1!=NULL){
        curr->next = list1;
        curr = curr->next;
        list1 = list1->next;
    }
    while(list2!=NULL){
        curr->next = list2;
        curr = curr->next;
        list2 = list2->next;
    }
    return result;
}
