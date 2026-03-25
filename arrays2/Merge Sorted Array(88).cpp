#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l =m-1; int r =0;
        while(l>=0 && r<n){
            if(nums1[l]>nums2[r]){
                //wrong swap pleas
                swap(nums1[l],nums2[r]);
            }else{
                break;
            }
            l--;
            r++;
        }
        // now please sort both
        sort(nums1.begin(), nums1.begin()+m);
        sort(nums2.begin(), nums2.end());

        for(int i=0 ; i<n ; i++){
            nums1[m+i]=nums2[i];
        }
        
    }
};