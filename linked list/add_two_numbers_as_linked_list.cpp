//https://www.interviewbit.com/problems/add-two-numbers-as-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    int countA = 0;
    int countB = 0;
    ListNode* temp = A;
    while(temp){
        countA++;
        temp = temp -> next;
    }
    temp = B;
    while(temp){
        countB++;
        temp = temp -> next;
    }
    // cout << countA << endl;
    // cout << countB << endl;
    
    if(countB > countA){
        ListNode* temp = A;
        A = B;
        B = temp;
    }
    // cout << A->val << endl;
    // cout << B->val << endl;
    
    ListNode* ans = new ListNode(0);
    ans -> next = A;
    ListNode* prev = ans;
    int curr;
    int carry = 0;
    while(A && B){
        curr = A->val + B->val + carry;
        // cout << curr << endl;
        A -> val = curr%10;
        carry = curr/10;
        A = A -> next;
        prev = prev -> next;
        B = B -> next;
    }
    while(A){
        curr = A -> val + carry;
        // cout << curr << endl;
        A -> val = curr%10;
        carry = curr/10;
        A = A -> next;
        prev = prev -> next;
    }
    if(carry){
        prev -> next = new ListNode(carry%10);
        carry = carry / 10;
        prev = prev -> next;
    }
    
    return ans->next;
}
