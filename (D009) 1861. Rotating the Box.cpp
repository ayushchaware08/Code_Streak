// ----------- M1:  Brute force --------------
// TC = O(m n^2) -- worse  (m: row n: col)
// SC = O(m n)


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // S1. Rotate Matrix (transpose then reverse rows)
      
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m));

        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }
        // reverse each rows
        for (int i = 0; i < n; i++) {
            reverse(result[i].begin(), result[i].end());
        }

      
        // S2. Apply gravity effect on box
      
        for (int j = 0; j < m; j++) { // each column
            // from botom to top each col
            for (int i = n - 1; i >= 0; i--) {
                if (result[i][j] == '.') { // found empty '.'
                    int nextRowStone = -1;
                    // search stone directly above '.'
                    for (int k = i - 1; k >= 0; k--) {
                        if (result[k][j] == '*') { // found obstracle
                            break;
                        }
                        if (result[k][j] == '#') { // found stone
                            nextRowStone = k;
                            break;
                        }
                    }

                    // stone found above empty
                    if (nextRowStone != -1) {
                        result[nextRowStone][j] = '.';
                        result[i][j] = '#';
                    }
                }
            }
        }
        return result;
    }
};
