// bf by using 2 loop 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for(ListNode* a = headA ; a!= NULL ; a = a->next){
            for(ListNode* b = headB ; b!= NULL ; b=b->next){
                if(a==b) return a;
            }
        }
        return NULL;
        
    }
};
//using set - store the nodes of first list in a set and then iterate the second list and check if any node is present in the set and return that node
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode* >st;
        for(ListNode* a =headA ; a!= NULL ; a= a->next){
            st.insert(a);
        }
        for(ListNode* b = headB ; b!= NULL ; b=b->next){
            if(st.find(b) != st.end()) return b;
        }
        return NULL;
        
    }
};
class Solution {
public:
    int getlen(ListNode* head){
        int len =0;
        while(head){
            head= head->next;
            len++;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = getlen(headA);
        int lb = getlen(headB);
         while(la>lb){
            headA=headA->next;
            la--;
         }
         while(la<lb){
            headB=headB->next;
            lb--;
         }

         while(headA != NULL || headB != NULL ){
            if(headA == headB) return headB;
            headA=headA->next;
            headB = headB->next;
         }
         return NULL;
        
    }
};