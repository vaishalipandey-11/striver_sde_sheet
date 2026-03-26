#include<bits/stdc++.h>
using namespace std;
// bf approach each cell
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n ; i++){
            for(int j=0; j<m ; j++){
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
    }
};

// better binary search approach // binary search on each row 
class Solution {
public:
    bool binarysearch(vector<int>&mat , int target){
        int start = 0 ; int end = mat.size()-1;
        while(start<=end){
            int mid = end+(start-end)/2;
            if(mat[mid] == target){
                return true;
            }else if(mat[mid]<target){
                start = mid+1;

            }else end = mid-1;

        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int n = matrix.size(); int m = matrix[0].size();
    int start = 0 ; int end = m-1;
    for(int i=0; i<n ; i++){
        if(matrix[i][start]<=target && matrix[i][end]>=target){
           return binarysearch(matrix[i],target);
        }
    }
    return false;
        
    }
};

// best approach ... look it as 1D array and find row col of index and move in binary search 
