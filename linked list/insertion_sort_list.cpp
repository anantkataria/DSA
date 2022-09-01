// https://leetcode.com/problems/insertion-sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* next; 
        
        while(curr != nullptr){
            next = curr -> next;
            
            while(prev->next!=nullptr && prev->next->val<curr->val){
                prev = prev -> next;
            }
            
            curr -> next = prev -> next;
            prev -> next = curr;
            curr = next;
            prev = dummy;
        }
        
        return dummy->next;
    }
};