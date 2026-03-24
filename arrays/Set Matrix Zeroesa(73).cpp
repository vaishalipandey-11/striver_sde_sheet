#include<bits/stdc++.h>
using namespace std;
//just take 2 vectors and mark the row and col which has 0 and 
//then in next loop make all those row and col 0  
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() ; int m = matrix[0].size();
        vector<int>row(n,0);
        vector<int>col(m,0);
        for(int i=0; i<n ; i++){
            for(int j =0;  j<m ; j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for(int i=0; i<n ; i++){
            for(int j=0; j<m ; j++){
                if(row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};

// here we are marking the row and col with -100000 and then in next loop we are making those 
// row and col 0
class Solution {
public:
    void row(vector<vector<int>>& matrix, int i, int m) {
        for (int j = 0; j < m; j++) {
            if(matrix[i][j] !=0){ // important to check if its not 0 because if we mark 0 as -100000 then we will not be able to mark that row and col as 0 in next loop`
                matrix[i][j] = -100000;
            }
        }
    }
    void col(vector<vector<int>>& matrix, int j, int n) {
        for (int i = 0; i < n; i++) { 
              if(matrix[i][j] !=0){
                matrix[i][j] = -100000;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i <n ; i++){
            for(int j=0; j<m ; j++){
                if(matrix[i][j]==0){
                    row(matrix,i,m);
                    col(matrix,j,n);
                }
            }
        }

        for(int i=0; i<n ; i++){
            for(int j=0; j<m ;j++){
                if(matrix[i][j]==-100000){
                    matrix[i][j]=0;
                }
            }
        }
    }
};