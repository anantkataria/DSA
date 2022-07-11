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
    ListNode* newHead = A;
    A = A -> next;
    ListNode* nextStorage;
    ListNode* traversal;
    ListNode* prev;
    while(A){
        nextStorage = A -> next;
        traversal = newHead;
        while(traversal && traversal -> val < A -> val){
            traversal = traversal -> next;
        }
        A -> next = traversal -> next;
        traversal -> next = A;
        A = nextStorage;
    }
    return newHead;
}