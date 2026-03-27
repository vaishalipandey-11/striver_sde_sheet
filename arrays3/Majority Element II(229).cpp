// hint - 2 se jada majority element nhi hote
// m1 using 2 loops store the freq of each element and return the element with freq > n/3
//m2 hashmap mini  freq = n/3+1 store the freq and return the element with freq > n/3
//m3 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;

        for(int i=0; i<n ; i++){
            if(res.size()==0 || res[0] != nums[i]){
                int count =0;
                for(int j =0; j<n ; j++){
                    if(nums[i]==nums[j]) count++;
                }
                if(count >n/3) res.push_back(nums[i]);
            }
            if(res.size()==2) return res;
        }
        return res;
        
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        unordered_map<int,int>mp;
        int mini = int(n/3)+1;

        for(int i=0; i<n ; i++){
            mp[nums[i]]++;
            if(mp[nums[i]]== mini){
                res.push_back(nums[i]);
            }
            if(res.size() == 2) return res;
        }
        return res;
        
    }
};