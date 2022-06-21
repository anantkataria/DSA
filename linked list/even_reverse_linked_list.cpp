//https://www.interviewbit.com/problems/even-reverse/

//Approach 1
// Store the even positioned and odd positioned
// nodes in 2 vectors. now reverse the even position vectors
// and then Recombine them to form a linked list.
// All of this will happen in O(n) time.

//Approach 2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* temp;
    while(curr != nullptr){
        temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
 
ListNode* Solution::solve(ListNode* A) {
    if(!A || !A->next)
        return A;
    ListNode* newList = new ListNode(0);
    ListNode* newListHead = newList;
    ListNode* temp = A;
    int count = 1;
    while(temp){
        if(count%2 == 0){
            newList->next = new ListNode(temp->val);
            newList = newList -> next;
        }
        temp = temp -> next;
        count++;
    }
    
    newListHead->next = reverseList(newListHead->next);
    
    count = 1;
    temp = A;
    newList = newListHead -> next;
    while(temp){
        if(count%2 == 0){
            temp -> val = newList -> val;
            newList = newList -> next;
        }
        temp = temp -> next;
        count++;
    }
    
    return A;
}
