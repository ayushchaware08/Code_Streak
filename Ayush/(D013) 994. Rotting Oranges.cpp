// Approach BFS traversal
// TC = O(m*n) // grid m*n
// SC = O(m*n)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited = grid; // state of orange

        queue<pair<int, int>> q; // <rotton orange, count of fresh org>
        int countFreshOrange = 0;

        // add all rotton oranges to queue
        for (int i = 0; i < m; i++) { 
            for (int j = 0; j < n; j++){
                if (visited[i][j] == 2){ // rotton
                    q.push({i, j});
                }
                if (visited[i][j] == 1){ // fresh
                    countFreshOrange++;
                }
            }
        }
        
        if (countFreshOrange == 0) // no fresh orange
            return 0;
        if (q.empty()) // no rotten oranges
            return -1;
        
        // BFS Traversal

        int minutes = -1;
       
        vector<pair<int, int>> direction = {{1, 0},{-1, 0},{0, -1},{0, 1}}; // four directions i.e. up, down, left, right
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [x, y] = q.front(); // curr rotton orange
                q.pop();
                // chech all direction
                for (auto [dx, dy] : direction) {
                    int i = x + dx; // row
                    int j = y + dy; // col
                    if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                        visited[i][j] = 2;  // mark rotton
                        countFreshOrange--; 
                        q.push({i, j}); // new rotton org
                    }
                }
            }
            minutes++; 
        }
        
        if (countFreshOrange == 0)
            return minutes;
        return -1;
    }
};
