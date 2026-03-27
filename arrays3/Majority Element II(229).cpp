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

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = 0, ele2 = 1; // initialize differently

        // Step 1: Find candidates
        for (int num : nums) {
            if (num == ele1) cnt1++;
            else if (num == ele2) cnt2++;
            else if (cnt1 == 0) {
                ele1 = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                ele2 = num;
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Step 2: Verify candidates
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == ele1) cnt1++;
            else if (num == ele2) cnt2++;
        }

        vector<int> ans;
        int n = nums.size();
        if (cnt1 > n/3) ans.push_back(ele1);
        if (cnt2 > n/3) ans.push_back(ele2);

        return ans;
    }
};