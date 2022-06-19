//https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* findKth(ListNode* curr, int k){
    while(curr && k){
        curr = curr -> next;
        k--;
    }
    return curr;
} 

ListNode* Solution::solve(ListNode* A, int k) {
    ListNode* dummy = new ListNode(0);
    ListNode* groupPrev = dummy;
    dummy -> next = A;
    bool doreverse = true;
    
    while(true){
        ListNode* kth = findKth(groupPrev, k);
        if(!kth)
            break;
        if(doreverse){
            ListNode* groupNext = kth -> next;
            ListNode* curr = groupPrev -> next;
            ListNode* prev = kth -> next;
            ListNode* temp;
            while(curr != groupNext){
                temp = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = temp;
            }
            temp = groupPrev -> next;
            groupPrev -> next = kth;
            groupPrev = temp;
            doreverse = false;
        }
        else {
            groupPrev = kth;
            doreverse = true;
        }
        
    }
    
    return dummy -> next;
}
