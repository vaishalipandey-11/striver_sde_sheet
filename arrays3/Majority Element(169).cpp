// m1 by  2 loop over the array if freq ==[n/2] ret
// m2 by hashmap store freq and return the element with freq > n/2
// m3 by using count and candidate variable
// m4 by sorting the array and return the element at n/2 index
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int number = -1;
        for(auto &it : nums){
            if(count ==0 ) number = it;
            if(number == it) count++;
            else  count --;
        }
        return number;

        
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};