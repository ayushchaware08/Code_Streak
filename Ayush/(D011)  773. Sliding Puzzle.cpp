// TC = (m*n)! * (m*n)  -- BFS better than DFS
// SC = (m.n)!
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // basicallya map tha store direction of the element
        vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5},
                                          {0, 4}, {1, 3, 5}, {2, 4}};

        string target = "123450"; // goal state
        string startState;  // initial state

        // Convert the 2D board into a string representation
        // iterate to board
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                startState += to_string(board[i][j]); // append each tile to str
            }
        }

        unordered_set<string> visited;  // To store visited states
        queue<string> queue; // req for BFS
        queue.push(startState);
        visited.insert(startState);

        int moves = 0;

        // BFS
        while (!queue.empty()) {
            int size = queue.size();
            while (size-- > 0) {
                string currentState = queue.front();
                queue.pop();

                // reached the target
                if (currentState == target) {
                    return moves; 
                }

                int zeroPos = currentState.find('0');
                for (int newPos : directions[zeroPos]) {
                    // generation of next  state
                    string nextState = currentState;
                    swap(nextState[zeroPos], nextState[newPos]);

                    // already visited
                    if (visited.count(nextState)) continue;

                    // Mark the new state as visited and add it to the queue
                    visited.insert(nextState);
                    queue.push(nextState);
                }
            }
            moves++;
        }
        return -1;
    }
};
