// --------- Optimal One ----------
// TC: O(2*N*M)
// SC: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // vector<int> col(m, 0); -> matrix[0][ ]
        // vector<int> row(n, 0); -> matrix[ ][0]

        int col0 =1;
        // mark row col 1 if at least one 0
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(matrix[i][j]==0){
                    // mark ith row
                    matrix[i][0] =0;
                    
                    // mark jth col (handle edge case)
                    if(j!=0) matrix[0][j] =0;
                    else col0=0;
                }
            }
        }
        // replacing with 0 (ignore front row col)
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                //
                if(matrix[i][j] != 0){
                    // check for col row
                    if(matrix[0][j]==0 || matrix[i][0]==0){
                        matrix[i][j] =0;
                    }
                }
            }
        }
        if(matrix[0][0] ==0){
            for(int j =0; j<m; j++) matrix[0][j] =0;
        }
        if(col0 ==0){
            for(int i =0; i<n; i++) matrix[i][0] =0;
        }
    }
};


// ----------- Better one -----------
// TC: o(2*n*m)
// SC: o(n*m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> col(m, 0);
        vector<int> row(n, 0);

        // mark row col 1 if at least one 0
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(matrix[i][j]==0){
                    row[i] =1;
                    col[j] =1;
                }
            }
        }

        // mark them 0 now
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(row[i]==1 || col[j]==1){
                    matrix[i][j] =0;
                }
            }
        }
    }
};


// ---------- Brute force (not accepted;( ) ------------
// TC: O((N*M)*(N + M)) + O(N*M)
// SC: O(1)
class Solution {
public:
    void markRow(vector<vector<int>>& matrix, int i, int m){
        for(int j=0; j<m; j++){
            if(matrix[i][j] != 0){
                matrix[i][j] = INT_MIN;
            }
        }
    }

    void markCol(vector<vector<int>>& matrix, int j, int n){
        for(int i=0; i<n; i++){
            if(matrix[i][j] != 0){
                matrix[i][j] = INT_MIN;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
     for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            if(matrix[i][j]==0){
                markRow(matrix, i, m);
                markCol(matrix, j, n);
            }
        }
     }   
    // mark -1 to 0
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == INT_MIN) {
                matrix[i][j] = 0;
            }
        }
    }
    }
};