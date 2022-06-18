//https://www.interviewbit.com/problems/kth-node-from-middle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int findMiddleElement(ListNode* A){
    int count = 0;
    ListNode* slow = A;
    ListNode* fast = A;
    
    while(fast && fast -> next){
        fast = fast -> next -> next;
        slow = slow -> next;
        count++;
    }
    
    return count;
}
 
int Solution::solve(ListNode* A, int B) {
    int middleElement = findMiddleElement(A);
    int count = middleElement - B;
    if(count < 0)
        return -1;
    while(count){
        A = A-> next;
        count--;
    }
    
    return A->val;
}
