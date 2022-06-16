// https://www.interviewbit.com/problems/sort-binary-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    ListNode* temp = A;
    int zeros = 0;
    int ones = 0;
    while(temp){
        if(temp->val == 0)
            zeros++;
        else
            ones++;
        temp = temp->next;
    }
    
    temp = A;
    while(zeros > 0){
        temp->val = 0;
        zeros--;
        temp = temp->next;
    }
    
    while(ones > 0){
        temp->val = 1;
        ones--;
        temp = temp->next;
    }
    
    return A;
}
