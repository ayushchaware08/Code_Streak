// TC = O(nm)
// SC = O(nm)
// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/

class Solution {
    void visitRowCol(int row, int col, vector<vector<char>>& grid){
        // upward
        for(int r = row -1; r>= 0; r--){
            if(grid[r][col]=='W'|| grid[r][col]=='G') break;
            grid[r][col]='V';
        }
        // down
        for(int r = row+1; r<grid.size(); r++){
            if(grid[r][col]=='W' || grid[r][col]=='G') break;
            grid[r][col]='V';
        }
        // left
        for(int c = col-1;c>=0;c--){
            if(grid[row][c]=='W'||grid[row][c]=='G') break;
            grid[row][c]='V';
        }
        // right
        for(int c = col+1;c<grid[0].size();c++){
            if(grid[row][c]=='W'||grid[row][c]=='G') break;
            grid[row][c]='V';
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
         vector<vector<char>> grid(m, vector<char>(n, '.'));
        // mark every cell as empty
            for(int i =0; i<m;i++){
                for(int j =0; j<n; j++){
                    grid[i][j] = '.';
                }
            }
        // mark gaurd cell 
        for(const auto& guard: guards){
            grid[guard[0]][guard[1]] = 'G';
        }
        // mark wall
        for(const auto& wall: walls){
            grid[wall[0]][wall[1]] = 'W';
        }
        // visit all gaurd horizontal and verticle direc
        for(const auto& guard: guards){
            visitRowCol(guard[0], guard[1],grid);
        }


        // out ans
        int cnt =0; 
        for(const auto& row : grid){
            for(char cell:row){
                if(cell == '.') cnt++;
            }
        }
        return cnt;
    }
};
