// Better one - Binary search


// Brute force
// TC: O(nm + nm log nm)
// SC o(nm)
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int m = mat.size(); //col
        int n = mat[0].size(); // rows
        
        vector<int> arr;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                arr.push_back(mat[i][j]);
            }
        }
        
        sort(arr.begin(), arr.end());
        
        return arr[arr.size()/2];
    }
};