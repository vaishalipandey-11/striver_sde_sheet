#include <bits/stdc++.h>
using namespace std;
// brute force - O(n^2) approach
class Solution {
public:    int longestZeroSumSubarray(vector<int>& nums) {
        int n = nums.size();
        int longest =0;
        for(int i=0; i<n ; i++){
            int sum =0;
            for(int j=i ; j<n ; j++){
                sum+=nums[j];
                if(sum==0){
                    longest = max(longest , j-i+1);
                }
            }
        }
        return longest;
    }
};  

// optimal - using prefix sum and hashing
class Solution {
public:    int longestZeroSumSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp; // prefix sum and its first index
        int longest =0;
        int prefixSum =0;
        for(int i=0; i<n ; i++){
            prefixSum+=nums[i];
            if(prefixSum==0){
                longest = max(longest , i+1);
            }else if(mp.find(prefixSum) != mp.end()){
                longest = max(longest , i - mp[prefixSum]);
            }else{
                mp[prefixSum] = i; // store the first index of this prefix sum
            }
        }
        return longest;
    }
};  