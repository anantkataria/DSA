//https://leetcode.com/problems/partition-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* head, int B) {
    ListNode* before = new ListNode(0);
    ListNode* after = new ListNode(0);
    ListNode* beforeHead = before;
    ListNode* afterHead = after;
    
    while(head){
        if(head -> val < B){
            before -> next = head;
            before = before -> next;
        }
        else {
            after -> next = head;
            after = after -> next;
        }
        head = head -> next;
    }
    
    after -> next = NULL;
    before -> next = afterHead -> next;
    ListNode* newHead = beforeHead -> next;
    free(beforeHead);
    free(afterHead);
    return newHead;
}
