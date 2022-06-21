// https://www.interviewbit.com/problems/rotate-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int findListLen(ListNode* head){
    int count = 0;
    while(head){
        head = head -> next;
        count++;
    }
    return count;
} 

ListNode* Solution::rotateRight(ListNode* A, int B) {
    int length = findListLen(A);
    int rotate = B % length;
    if(rotate == 0)
        return A;
    
    int count = length - rotate;
    ListNode* dummy = new ListNode(0);
    dummy -> next = A;
    ListNode* temp = dummy;
    ListNode* newLast;
    ListNode* oldLast;
    ListNode* newHead;
    while(temp && count){
        temp = temp -> next;
        count--;
    }
    newLast = temp;
    newHead = temp -> next;
    while(temp -> next){
        temp = temp -> next;
    }
    oldLast = temp;
    
    newLast -> next = nullptr;
    oldLast -> next = dummy -> next;
    dummy -> next = newHead;
    
    return dummy -> next;
}
