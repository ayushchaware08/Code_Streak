// TC O(n) 
// SC O(1)
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int winner =0; // assume team 0 is winner
        // let opponent = i
        for(int i = 0; i<grid[0].size(); i++){
            if(i == winner){ // that i=j conditon
                continue;
            }
            if(grid[winner][i] == 0){
                winner = i; // strong team
            }
        }
        return winner;
    }
};
