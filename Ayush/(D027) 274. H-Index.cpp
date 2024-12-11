// Brute force (same with Binary search)
// TC: O(nLogn) due to sort
// SC: O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans =0, n = citations.size();

        for(int i =0; i<n; i++){
            // main condition
            if(citations[i]>=n-i){
                ans = max(ans, n-i);
            }
        }
        return ans;
    }
};