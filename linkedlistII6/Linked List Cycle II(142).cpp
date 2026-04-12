//bf - by set 
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;    
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        while (head) {
            if (st.empty()) {
                st.insert(head);    
                head = head->next;
            } else if (st.find(head) != st.end()) {
                return head;
            } else {
                st.insert(head);
                head = head->next;
            }
        }
        return NULL;
    }
};  

// using slow and fast method - if there is a cycle then slow and fast will meet at some point and then we can find the starting point of the cycle by moving one pointer to the head and another pointer to the meeting point and then move both pointers one step at a time until they meet again and that will be the starting point of the cycle
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow ->next ;
            fast = fast->next->next;
             if(slow == fast ) {
                ListNode* temp = head;
                while(temp != slow){
                    temp = temp->next;
                    slow = slow->next;
                }
                return temp;
             }
        }
        return NULL;
        
    }
};