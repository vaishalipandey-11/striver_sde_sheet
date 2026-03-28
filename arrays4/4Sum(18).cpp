#include <bits/stdc++.h>
using namespace std;
// bf approach 4 loops + sorting + set to avoid duplicates
//better  3loops + sorting + set to avoid duplicates
// best approach 2 loops + sorting + 2 pointers + set to avoid duplicates


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {

                        long long sum =
                            (long long)nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k],
                                                nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                unordered_set<long long> seen;
                for (int k = j + 1; k < n; k++) {

                    long long t = target;
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long need = t - sum;

                    if (seen.find(need) != seen.end()) {

                        vector<int> temp = {nums[i], nums[j], nums[k], (int )need};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);

                    }
                    seen.insert(nums[k]);
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // rem duplicate

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int s = j + 1;
                int l = n - 1;

                while (s < l) {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[s] + nums[l];

                    if (target == sum) {
                        ans.push_back({nums[i], nums[j], nums[s], nums[l]});
                        while (s < l && nums[s] == nums[s + 1])
                            s++;
                        while (s < l && nums[l] == nums[l - 1])
                            l--;

                        s++;
                        l--;
                    }else if(sum<target){
                        s++;
                    }else{
                        l--;
                    }   
                }
            }
        }
        return ans;
    }
};
