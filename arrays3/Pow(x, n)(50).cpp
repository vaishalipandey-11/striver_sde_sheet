//bf approach 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1) return 1;
        long long  temp = n ;
       double ans =1;

        if(n<0){
            x=1/x;
            temp = -1*1LL*n;
        }
        for(int i=0 ; i<temp ; i++){
            ans *=x;
        }
        return ans;
    }
};
// better approach
class Solution {
public:
    double myPow(double x, int n) {
        long long temp =n;
        double ans = 1;

        if(n==0 || x == 1) return 1;

        if(temp <0){
            x=1/x;
            temp = -temp;
        }

        while(temp>0){
            if(temp%2==1){ //odd
                ans*= x;
            }
             x*=x;
             temp /=2;
        }
        return ans;
        
    }
};