// using hashmap - optimal 
// o(1) O(1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                char curr = board[i][j];
                // unique index to each row
                int boxIndex = (i / 3) * 3 + (j / 3); 
                if (row[i].count(curr) || 
                    col[j].count(curr) || 
                    box[boxIndex].count(curr)) { // exists
                    return false;
                }
                // not exixts
                row[i].insert(curr);
                col[j].insert(curr);
                box[boxIndex].insert(curr);
            }
        }

        return true;        
    }
};

// TLE
class Solution {
public:
    bool checkrow(vector<vector<char>>& board,int j, char ch){
        int i =0;
        while(i<board.size()){
            if (i!=j && board[j][i++] == ch) return 0;
        }
        return 1;
    }

    bool checkcol(vector<vector<char>>& board,int i, char ch){
        int j =0;
        while(j<board.size()){
            if (i!=j && board[j++][i] == ch) return 0;
        }
        return 1;
    }

    bool checkbox(vector<vector<char>>& board,int i,int j, char ch){
        return 1;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j =0; j<board[0].size(); j++){
                if(board[i][j]!='.'){
                    if(checkrow(board, j, board[i][j])==1 &&
                     checkcol(board, i, board[i][j])==1 &&
                     checkbox(board, i,j, board[i][j])==1){
                        return 0;
                    }
                }
                else continue;
            }
        }
        return 1;
    }
};()