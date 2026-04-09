//using 2 pounters slow and fast , when fast reaches end slow will be at n-k th node
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;     
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};
// 19. Remove Nth Node From End of List
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        for(int i=0; i<n ; i++){
            fast=fast->next;
        }
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
//bf - get length of list then return n-k th node

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    int l =0;
    ListNode* node = head;
    while(node){
        l++;
        node= node->next;
    }
    if(l==n) return head->next;
    ListNode* slow = head;
    for(int i=0; i<(l-n-1); i++){
        slow = slow->next;

    }
    slow->next = slow->next->next;
    return  head;

    }
};