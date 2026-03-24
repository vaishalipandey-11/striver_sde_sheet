#include<bits/stdc++.h>
using namespace std;
/// find gola 3<5 where i of 3 is gola
// then find the element just greater than 3 from right side and swap it with 3
// then reverse the array from gola+1 to end
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

    int n = nums.size();
    int gola = -1;
    for(int i=n-1; i>0 ; i-- ){
        if(nums[i-1]<nums[i]){
            gola = i-1;
            break;
        }
    }

    if(gola != -1){
        for(int j=n-1 ; j>gola ; j-- ){
            if(nums[j]> nums[gola]){
                swap(nums[j],nums[gola]);
                break;
            }
        }
    }

    reverse(nums.begin()+gola+1, nums.end());
    }
};