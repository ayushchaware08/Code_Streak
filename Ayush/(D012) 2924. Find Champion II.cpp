// indegree count Approach (no indegree means Champion)
// OPTIMIZED by runtime
// TC = O(n+m) 
// SC = O(n) 

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
       vector<int> indegree(n, 0); // size n , initilized with 0
        // Calculate indegree
        for (const vector<int>& edge : edges) {
        // for (auto edge: edges){   // reduces the runtime of code (0MS)
            indegree[edge[1]]++;
        }

        int champion = -1;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) { // champion team
                if(champion != -1){ 
                    // allredy found champion team
                    return -1;
                }
                champion = i; // first champion (the only one)
            }
        }
        return champion; 
    }
};

// indegree count Approach (no indegree means Champion)
// TC = O(n+m) m:to iterate for indegree of all teams, n: to iterate for zero indegree
// SC = O(n) (indegree vector)

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
       vector<int> indegree(n, 0); // size n , initilized with 0
        // Calculate indegree
        for (auto edge : edges) {
            indegree[edge[1]]++;
        }

        int champion = -1, champCount = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) { // champion team
                champCount++;
                champion = i;
            }
        }

        // champcount > 1 , -1
        // champcount == 0 , champion
        return champCount > 1 ? -1 : champion; 
    }
};
