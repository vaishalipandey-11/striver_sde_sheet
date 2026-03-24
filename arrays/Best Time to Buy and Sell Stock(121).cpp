#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int currmax = 0;
        for (int i = 1; i < n; i++) {
            buy = min(buy, prices[i]);
            currmax = max(currmax, prices[i] - buy);
        }
        return currmax;
    }
};