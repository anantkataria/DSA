// https://www.interviewbit.com/problems/insertion-sort-list/
// https://www.youtube.com/watch?v=gwW8U4exaYs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* newHead = new ListNode(-1);
    ListNode* nextStorage;
    ListNode* traversal;
    while(A){
        nextStorage = A -> next;
        traversal = newHead;
        while(traversal -> next && traversal -> next -> val < A -> val){
            traversal = traversal -> next;
        }
        A -> next = traversal -> next;
        traversal -> next = A;
        A = nextStorage;
    }
    return newHead -> next;
}
