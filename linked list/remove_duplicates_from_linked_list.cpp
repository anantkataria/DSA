// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A || !A->next){
        return A;
    }
    
    ListNode* dummy = new ListNode(0);
    dummy -> next = A;
    A = dummy;
    ListNode* temp = A;
    ListNode* temp1;
    
    while(temp->next){
        temp1 = temp -> next;
        while(temp1 -> next && temp1 -> val == temp1 -> next -> val){
            temp1 = temp1 -> next;
        }
        if(temp->next != temp1){
            temp -> next = temp1 -> next;
        }
        else{
            temp = temp -> next;
        }
    }
    
    return A -> next;
}
