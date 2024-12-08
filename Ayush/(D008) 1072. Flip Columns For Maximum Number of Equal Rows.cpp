// using hashmaps
// TC = O(MN)
// SC = O(M)

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // map having key: pattern str  and value: occr cnt
        unordered_map<string, int> patternFrequency;
        
        for (const auto& row : matrix) {
            string pattern;
            for (int col = 0; col < row.size(); col++) 
            {
                // T: for matching F: Differ
                pattern += (row[0] == row[col] ? 'T' : 'F');
            }
            patternFrequency[pattern]++;
        }
        
        // to find max freq
        int maxFreq = 0;
        for (const auto& pair : patternFrequency) {
            maxFreq = max(maxFreq, pair.second);
        }
        
        return maxFreq;
    }
};
