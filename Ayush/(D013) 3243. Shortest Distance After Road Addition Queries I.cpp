// Can be solved using Dynamic Programming
// TC = O(q*(v+e))  [BFS v: vertices e: edge q: query]
// TC = O(v+e)

class Solution {
    int bfs(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);
    queue<int> nodeQueue;
    nodeQueue.push(0);
    visited[0] = true;
    
    int currentLayerNodeCount = 1;  // Nodes at current distance
    int nextLayerNodeCount = 0;     // Nodes at next distance
    int layersExplored = 0;         // Current distance/edges count
    
    while (!nodeQueue.empty()) {
        // Process all nodes at current distance
        for (int i = 0; i < currentLayerNodeCount; i++) {
            int currentNode = nodeQueue.front();
            nodeQueue.pop();
            
            if (currentNode == n-1)  // Found destination
                return layersExplored;
                
            // Add unvisited neighbors to queue
            for (int neighbor : adjList[currentNode]) {
                if (!visited[neighbor]) {
                    nodeQueue.push(neighbor);
                    visited[neighbor] = true;
                    nextLayerNodeCount++;
                }
            }
        }
        // Move to next layer/distance
        currentLayerNodeCount = nextLayerNodeCount;
        nextLayerNodeCount = 0;
        layersExplored++;
    }
    return -1;  // Unreachable in this problem
    }
    
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
           
           vector<vector<int>> adjList(n);
           for(int i = 0; i<n-1; i++){
            adjList[i].push_back(i + 1);
           }

           vector<int> ans;

           for(auto& road: queries){
            adjList[road[0]].push_back(road[1]); // new road added
            ans.push_back(bfs(n, adjList)); // new shortest path
           }

           return ans;
    }
};

