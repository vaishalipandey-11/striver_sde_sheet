//bf - copy into array then 2 pointer approach to check if palindrome
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
public:    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        int i=0 , j = arr.size()-1;
        while(i<j){
            if(arr[i] != arr[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};  

// using stack method - push the first half of the list into stack and then compare with the second half of the list
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while (temp) {
            st.push(temp->val);
            temp = temp->next;
        }
        while (!st.empty()) {
            int val = st.top();
            if (val != head->val) {
                return false;
                break;
            }
            st.pop();
            head = head->next;
        }
        return true;
    }
};
// middle and reverse method - find the middle of the list and reverse the second half of the list and then compare the first half and the reversed second half
class Solution {
public:
    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (!head || !head->next )
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        //middle
        while (fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = reverse(slow);
        ListNode* first = head;

        while(temp ){
            if(temp->val != first->val) return false;
            temp= temp ->next;
            first = first->next;
        }
        return true;
    }
};