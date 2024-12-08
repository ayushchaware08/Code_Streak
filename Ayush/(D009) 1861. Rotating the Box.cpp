// Combine rotation and gravity operation
// TC = O(m n) 
// SC = O(m n)


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // S1. Rotate Matrix 90 degree (transpose then reverse rows)
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m, '.')); // initilized with all '.' empty

        // gravity effect + rotation
        for(int i = 0; i<m; i++){ //each col
            int lowestRowEmptyCell = n-1;
            for(int j = n -1; j>=0; j--){ // each row in reverse order
                if(box[i][j] == '#'){ // found stone
                    // placing at right position
                    // result[i][j] = '.';
                     result[lowestRowEmptyCell][m-i-1] ='#'; // row and col of rotated matrix
                    // m-1 is rightmost position Subtracting i moves left to right (i.e traspose+ reverse)
                    lowestRowEmptyCell--;
                }
                //  OPTIMIZATION
                else if (box[i][j] == '*') { // found obstracle
                    result[j][m - i - 1] = '*';
                    lowestRowEmptyCell = j - 1;

                }
            }
        }
        return result;
    }
};
// Combine rotation and gravity operation
// TC = O(m n) 
// SC = O(m n)


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // S1. Rotate Matrix 90 degrees (transpose then reverse rows)
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m, '.')); // initialised with all '.' empty

        // gravity effect + rotation
        for(int i = 0; i<m; i++){ //each col
            int lowestRowEmptyCell = n-1;
            for(int j = n -1; j>=0; j--){ // each row in reverse order
                if(box[i][j] == '#'){ // found stone
                    // placing at right position
                    // result[i][j] = '.';
                     result[lowestRowEmptyCell][m-i-1] ='#'; // row and col of rotated matrix
                    // m-1 is rightmost position Subtracting i moves left to right (i.e traspose+ reverse)
                    lowestRowEmptyCell--;
                }
                if(box[i][j] == '*'){ // found obstacle
                    result[j][m-i-1]= '*';
                    lowestRowEmptyCell = j-1;
                }
            }
        }
        return result;
    }
};

//  [M2] Brute force --------------------------- 
// TC = O(m n) -- OPTIMIZED  (m: row n: col)
// SC = O(m n) // as new matrix result


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // S1. Rotate Matrix 90 degrees (transpose then reverse rows)
        int m = box.size(); // no of rows
        int n = box[0].size(); // no of col // box[0] access first row .size() length
        vector<vector<char>> result(n, vector<char>(m)); // swapped dimension

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
                // (OPTIMIZATION)
                int lowestRowEmptyCell = n-1; // having empty row
            for (int i = n - 1; i >= 0; i--) {
                
                if(result[i][j] == '#'){ // found stone - so fall to lowest
                    result[i][j] = '.'; // marked empty
                    result[lowestRowEmptyCell][j] ='#'; // marked stone
                    lowestRowEmptyCell--;
                }
                if(result[i][j] == '*'){ // found obstackle - update it to 'lowestRowEmptyCell'
                    lowestRowEmptyCell = i-1;
                }
            }
        }
        return result;
    }
};

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
            // from bottom to top each col
            for (int i = n - 1; i >= 0; i--) {
                if (result[i][j] == '.') { // found empty '.'
                    int nextRowStone = -1;
                    // search stone directly above '.'
                    for (int k = i - 1; k >= 0; k--) {
                        if (result[k][j] == '*') { // found obstacle
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
