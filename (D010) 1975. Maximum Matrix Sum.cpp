
// OPTIMIZED Reduced runtime
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0, size = matrix.size(), min = 100000,neg_Count = 0;

        for (int i =0; i<size; ++i) { // row
            for (int j =0; j<size; ++j) {
                // + abs to sum
                totalSum += abs(matrix[i][j]);
                // count -ve s
                if (matrix[i][j] < 0) {
                    neg_Count++;
                }
                // min = min < abs(matrix[i][j])? min: abs(matrix[i][j]);
                if (min < abs(matrix[i][j])) {
                    min = min; 
                } else {
                    min = abs(matrix[i][j]);
                }
            }
        }

        if (neg_Count % 2 == 0) { 
           return totalSum;
        }
        else{ //(i.e odd no of -ves)
            return totalSum - 2 * min; // converts our smallest absolute value from positive to negative
        }
    }
};


// Approch 1 -------- 
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsVal = INT_MAX;
        int negativeCount = 0;

        for (auto& row : matrix) { // row
            for (int val : row) {
                // + abs to sum
                totalSum += abs(val);
                // count -ve s
                if (val < 0) {
                    negativeCount++;
                }
                minAbsVal = min(minAbsVal, abs(val));
            }
        }

        if (negativeCount % 2 != 0) { //(i.e odd no of -ves)
            totalSum -= 2 * minAbsVal; // converts our smallest absolute value from positive to negative
        }

        return totalSum;
    
    }
};
