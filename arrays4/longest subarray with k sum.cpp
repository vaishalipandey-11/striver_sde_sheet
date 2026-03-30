//same as 0 sum 
//now you need to check if prefix sum - k exists in the map or not
#include <bits/stdc++.h>
using namespace std;
class Solution {    
public:    int longestSubarrayWithKSum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp; // prefix sum and its first index
        int longest =0;
        int prefixSum =0;
        for(int i=0; i<n ; i++){
            prefixSum+=nums[i];
            if(prefixSum==k){
                longest = max(longest , i+1);
            }else if(mp.find(prefixSum - k) != mp.end()){
                longest = max(longest , i - mp[prefixSum - k]);
            }else{
                mp[prefixSum] = i; // store the first index of this prefix sum
            }
        }
        return longest;
    }
};  