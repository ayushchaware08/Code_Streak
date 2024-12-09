// Unorderes set
// TC: O(m+n)
// SC: O(set)

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> set(banned.begin(), banned.end());

        int curr_sum =0, cnt=0;

        for(int i =1; i<=n; i++){
            // skip banned
            if(set.count(i)) continue;
            curr_sum += i;
            if(curr_sum> maxSum) break;
            // valid counts
            cnt++;
        }
        return cnt;
    }
};
