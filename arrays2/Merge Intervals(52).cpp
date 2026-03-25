#include<bits/stdc++.h>
using namespace std;
// ask - does it overlap with last interval or not 
// non overlap if start > last ele ( ans.back()[1] ) so push start and end
// over lap if s < last so ,, change end = max(last , end) then just change lst ele 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>ans ;
        
        sort(intervals.begin(), intervals.end());

        for(int i=0; i<n ; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            //non overlapping
            if(ans.empty() || start >ans.back()[1]){
                ans.push_back({start,end});
            }else{//overlapping
            end = max(ans.back()[1],end);
            ans.back()[1]=end;

            }
        }
        return ans;
        
    }
};