#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;     
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};
// bf - create a dummy node and iterate both lists and add the values and carry and create new nodes for sum%10 and update carry as sum/10
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy ;
        int carry =0;
        while(l1 || l2|| carry){
            int sum= carry ;

            if(l1){
                sum += l1->val ;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
        }
         return dummy.next;
        

    }
};
//recursive approach - add the values and carry and create new node for sum%10 and update carry as sum/10 and call recursively for next nodes
class Solution {
public:
    ListNode* solve(ListNode* l1, ListNode* l2, int carry){
        if(!l1 && !l2 && carry ==0) return NULL; 
        int sum = carry ;

        if(l1) sum+=l1->val;
        if(l2) sum+=l2->val;

        ListNode* node = new ListNode(sum%10);

        node->next = solve( l1? l1->next:NULL , l2? l2->next:NULL , sum/10);
        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1 , l2 , 0);
        
    }
};