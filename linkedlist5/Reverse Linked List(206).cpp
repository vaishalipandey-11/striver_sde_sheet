#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};  

// 206. Reverse Linked List 
//iterative sol , focus on 3 pointers prev , curr and next
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head== NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
            
        }
        return prev;
        
    }
};
// reccursive sol , focus on 1 node at a time , reverse the rest of the list and then connect the current node to the rest of the list
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newhead= reverseList(head->next);// return node 4  , head at 4 
        head->next->next = head;
        head->next = NULL;
        
        return newhead;
    }
};