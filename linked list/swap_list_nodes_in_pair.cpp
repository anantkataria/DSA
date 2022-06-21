//https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* swap(ListNode* next1, ListNode* next2){
    next1 -> next = next2 -> next;
    next2 -> next = next1;
    return next2;
}
 
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode* dummy = new ListNode(0);
    dummy -> next = A;
    ListNode* curr = dummy;
    while(curr -> next && curr -> next -> next){
        curr -> next = swap(curr->next, curr -> next -> next);
        curr = curr -> next -> next;
    }
    return dummy -> next;
}
