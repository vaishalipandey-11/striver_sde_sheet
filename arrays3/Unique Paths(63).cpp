#include <bits/stdc++.h>
using namespace std;
// this is memo soln (top down )
class Solution {
public:
    int solve(int i , int j , vector<vector<int>>&dp){
       // bc
        if(i==0 && j==0) return 1 ;
        if(i<0 || j<0 ) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j]= solve(i-1, j , dp)+ solve(i , j-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m , vector<int>(n,-1));
       return solve(m-1,n-1,dp); // o index soo m*n = m-1 n-1
       
        
    }
};

// this is tabulation soln (bottom up)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,0));

        //bc fill
        for(int i=0; i<m ; i++) dp[i][0]=1;
        for(int j=0; j<n ; j++) dp[0][j]=1;

        // fill all dp
        for(int i=1 ; i<m ; i++){
            for(int j=1; j<n ; j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// space optimised soln
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n,1);

        for(int i=1 ; i<m ; i++){
            for(int j=1 ; j<n ; j++){
                dp[j]=dp[j]+dp[j-1];
            }
        }
        return dp[n-1];
        
    }
};