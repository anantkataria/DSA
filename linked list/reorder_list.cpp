// https://www.interviewbit.com/problems/reorder-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    
    if(!A || !A->next)
        return A;
    
    //find middle
    //slow will hold middle
    ListNode* dummy = new ListNode(0);
    dummy -> next = A;
    ListNode* slow = A;
    ListNode* fast = A;
    ListNode* middlePrev = dummy;
    ListNode* last; 
    while(fast && fast -> next){
        last = fast;
        fast = fast -> next -> next;
        middlePrev = slow;
        slow = slow -> next;
    }
    while(last -> next){
        last = last -> next;
    }
    
    
    //reverse from middle to end (slow to end)
    ListNode* curr = slow;
    ListNode* prev = nullptr;
    ListNode* temp;
    while(curr != nullptr){
        temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    middlePrev -> next = last;
    
    //rearrange
    ListNode* ptr1 = dummy->next;
    // cout << ptr1 -> val << endl;
    ListNode* ptr2 = last;
    // cout << ptr2 -> val << endl;
    ListNode* newList = new ListNode(0);
    ListNode* newListHead = newList;
    // while(ptr1!=last){
    //     cout << ptr1 -> val << endl;
    //     ptr1 = ptr1 -> next;
    // }
    // while(ptr2 != NULL){
    //     cout << ptr2 -> val << endl;
    //     ptr2 = ptr2 -> next;
    // }
    
    while(ptr1!=last && ptr2!=NULL){
        newList -> next = ptr1;
        ptr1 = ptr1 -> next;
        newList = newList -> next;
        newList -> next = ptr2;
        ptr2 = ptr2 -> next;
        newList = newList -> next; 
    }
    if(ptr1!=last)
        newList -> next = ptr1;
    return newListHead -> next;
}
