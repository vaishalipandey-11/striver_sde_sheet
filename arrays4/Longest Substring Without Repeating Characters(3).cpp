#include <bits/stdc++.h>
using namespace std;
//bf approach using 2 loop and hash vector to check if char is already present in the current window or not
class Solution {public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int len =0;
        for(int i=0; i<n ; i++){
            vector<bool>seen(256,false);
            for(int j=i ; j<n ; j++){
                if(seen[s[j]]){
                    break;
                }   
                seen[s[j]] = true;
                len = max(len , j-i+1);
            }
        }
        return len ;
    }
};  


//better approach using set to check if char is already present in the current window or not
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l =0;
        int len =0;
        vector<int>lastseen(256,-1);
        for(int r=0; r<n ; r++){
            if(lastseen[s[r]] != -1){
                l = max(l,lastseen[s[r]]+1);
            }
            len = max(len, r-l+1);
            lastseen[s[r]]= r; // mark the idx where did i see last char
        }
        return len ;
    }
};