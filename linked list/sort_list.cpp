//https://leetcode.com/problems/sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* ans = new ListNode(-1);
        ListNode* ansHead = ans;
        while(list1 && list2){
            if(list1->val < list2->val){
                ans -> next = list1;
                list1 = list1 -> next;
            }
            else{
                ans -> next = list2;
                list2 = list2 -> next;
            }
            ans = ans -> next;
        }
        if(list1){
            ans -> next = list1;
        }
        else {
            ans -> next = list2;
        }
        
        return ansHead -> next;
    }
    
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        
        while(fast && fast -> next){
            fast = fast -> next -> next;
            prev = slow;
            slow = slow -> next;
        }
        
        prev -> next = nullptr;
        return slow;
    }
 
ListNode* Solution::sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        
        ListNode* middleElement = findMiddle(head);
        ListNode* first = sortList(head);
        ListNode* second = sortList(middleElement);
        return merge(first, second);
}
