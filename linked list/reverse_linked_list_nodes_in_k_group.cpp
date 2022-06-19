//https://leetcode.com/problems/reverse-nodes-in-k-group/
//https://www.youtube.com/watch?v=1UOPsfP85V4

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;
        
        while(1) {
            ListNode* kth = findKth(groupPrev, k);
            if(!kth)
                break;
            
            ListNode* groupNext = kth -> next;
            ListNode* curr = groupPrev -> next;
            ListNode* prev = kth -> next;
            ListNode* tmp;
            while(curr != groupNext){
                tmp = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = tmp;
            }
            tmp = groupPrev -> next;
            groupPrev -> next = kth;
            groupPrev = tmp;
        }
        
        return dummy -> next;
    }
    
    ListNode* findKth(ListNode* curr, int k){
        while(curr && k > 0){
            curr = curr -> next;
            k--;
        }
        return curr;
    }
};