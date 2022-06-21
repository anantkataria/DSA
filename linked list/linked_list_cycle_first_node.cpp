// https://www.interviewbit.com/problems/list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if(!A || !A->next)
        return nullptr;
        
    ListNode* slow = A->next;
    ListNode* fast = A->next->next;
    while(fast && fast -> next){
        if(slow == fast)
            break;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    if(slow == fast){
        slow = A;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
    
    return nullptr;
}
