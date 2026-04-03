//bf -get n then return n/2
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n =0;
        ListNode *curr = head;
        while(curr){
            n++;
            curr= curr->next;
        }
          curr = head;
        for(int i=0; i<n/2 ; i++){
            curr= curr->next;
        }
        return curr;
    }
};
// better approach - 2 pointers slow and fast , when fast reaches end slow will be at middle
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast && fast->next){
        slow = slow->next;
        fast=fast->next->next;
       }
       return slow ;
        
    }
};
