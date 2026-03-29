#include <bits/stdc++.h>    
using namespace std;
//bf - x+1 , x+2... approach using counter
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest =0;

        for(int i=0; i<n ; i++){
            int x = nums[i];
            int count =1;

            while(find(nums.begin(), nums.end(), x+1) != nums.end()){
                x+=1;
                count++;
            }
            longest = max(count , longest);
        }
        return longest;
    }
};

// better -
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        sort(nums.begin(), nums.end());
        int longest =1;
        int count =1;
        for(int i=1 ; i<n ; i++){
            if(nums[i]==nums[i-1]+1){
                count++;
                longest=max(count , longest);
            }else if(nums[i] != nums[i-1]){
                count=1;
            }
        }
        return longest ;
    }
};

// optimal - using set to check if x+1 exists or not in O(1) time
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int longest =0;
        for(int num : st){
            if(st.find(num-1) == st.end()){
                int x = num;
               int  count =1;

                while(st.find(x+1) != st.end()){
                    count++;
                    x++;
                }

                longest = max(count, longest);
            }    
        }
    return longest;
    }
};