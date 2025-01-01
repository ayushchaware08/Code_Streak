// ------------- Clockwise rotaion ------------
// Optimal approch in place replacement;
// tc: o(n*n+ n*n)
// sc: o(1);
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Transpose
        for(int i = 0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse rows
        for(int i =0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};

// Brute force 
// TC: O(n*n)
// SC: O(n*n)
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateImage(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<vector<int>>  rotated(n, vector<int>(n,0));  //-//
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            rotated[j][n-1-i]=matrix[i][j];
        }
    }
    return rotated;
}

int main(){ 
    vector<vector<int>>  matrix;    
    matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int>> rotated = rotateImage(matrix);
    for(int i =0; i<rotated.size(); i++){
        for(int j=0; j<rotated[0].size(); j++){
            cout<<rotated[i][j]<<" ";
        }
        cout<<endl;
    }
}


// ------------- anticlock Rotation ----------

