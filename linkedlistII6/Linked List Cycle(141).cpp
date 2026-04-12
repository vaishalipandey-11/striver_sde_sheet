// using bf - set - store the nodes in a set and check if any node is repeated
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
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> st;
        while (head) {
            if (st.empty()) {
                st.insert(head);
                head = head->next;
            } else if (st.find(head) != st.end()) {
                return true;
            } else {
                st.insert(head);
                head = head->next;
            }
        }
        return false;
    }
};

// using slow and fast method
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow ->next ;
            fast = fast->next->next;
             if(slow == fast ) return true;
        }
        return false;
        
    }
};