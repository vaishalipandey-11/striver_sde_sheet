#include<bits/stdc++.h>
using namespace std;
// just check i == i+1  // check with 2 loops also // use hashmap also // using freq vector if f=2 ret
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
       
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-1 ; i++){
            if(nums[i]==nums[i+1]) return nums[i];
        }
        return -1;
        
    }
};

// check with 2 loops 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
       
        for(int i=0; i<n ; i++){
           for(int j=i+1 ; j<n ; j++){
            if(nums[i]==nums[j]) return nums[i];
           }

        }
        return -1;

        
    }
};

//