// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// TC = O(n)
// SC = O(k)

#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;

        int n = s.length();
        int l = 0, maxlen = 0;
        // int r = 0;
        for (int r = 0; r < n; r++) {
            // last seen posn before l || not present 
            if (hash.count(s[r]) == 0||hash[s[r]] < l  ) { // in range ?
                hash[s[r]] = r;
                maxlen = max(maxlen, r - l + 1);
            } else {
                //repeted char
                l = hash[s[r]] + 1;
                hash[s[r]] = r; // update last seen position
            }
        }
    return maxlen;
    }
};
