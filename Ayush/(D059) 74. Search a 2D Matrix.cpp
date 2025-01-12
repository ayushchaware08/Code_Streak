// imaginary flattan 2D to 1D then BS - optimal
// TC: O(log(n*m))
// SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low =0, high = n*m-1;

        // Binary search
        while(low<=high){
            int mid = (low+high)/2;
            int row = mid/m, col = mid%m;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target)  low = mid+1;
            else high = mid-1;
            }
        return false;
        }
    
};

// better one - select perticular row then BS
// TC: O(n+logm)
// SC: O(1)

// Brute force 
// o(n*m)