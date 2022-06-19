//https://www.interviewbit.com/problems/palindrome-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* temp;
    while(curr != nullptr){
        temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
} 

int Solution::lPalin(ListNode* A) {
    if(!A || !A->next){
        return 1;
    }
    ListNode* slow = A;
    ListNode* fast = A;
    while(fast -> next && fast -> next -> next){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    ListNode* temp = reverse(slow -> next);
    while(A && temp){
        if(A->val != temp -> val)
            return 0;
        A = A -> next;
        temp = temp -> next;
    }
    return 1;
}
    