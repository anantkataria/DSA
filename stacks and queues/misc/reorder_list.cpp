// https://leetcode.com/problems/reorder-list/

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



//STACK BASED
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        ListNode* temp = slow->next;
        slow -> next = NULL;
        stack<ListNode*> s;
        while(temp){
            s.push(temp);
            temp = temp -> next;
        }
        
        temp = head;
        while(!s.empty()){
            ListNode* newNext = s.top();
            s.pop();
            newNext -> next = temp -> next;
            temp -> next = newNext;
            temp = temp -> next -> next;
        }
    }
};

//CONSTANT SPACE
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* temp;
        while(curr != NULL){
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        
        ListNode* first = head;
        ListNode* second = prev;
        while(second -> next != NULL){
            temp = first -> next;
            first -> next = second;
            first = temp;
            
            temp = second -> next;
            second -> next = first;
            second = temp;
        }
    }
};