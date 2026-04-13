//vvvimp 

  //Definition for singly-linked list.
   struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;  // node before current group

        while (true) {
            // find kth node (end of group)
            ListNode* groupEnd = groupPrev;
            for (int i = 0; i < k; i++) {
                groupEnd = groupEnd->next;
                if (!groupEnd) return dummy->next;
            }

            ListNode* nextGroupStart = groupEnd->next;

            // reverse current group
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupPrev->next;

            while (curr != nextGroupStart) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // reconnect
            ListNode* groupStart = groupPrev->next; // old head → becomes tail
            groupPrev->next = groupEnd;
            groupPrev = groupStart;
        }
    }
};