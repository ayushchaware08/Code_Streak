// optimized

// brute
// TC: o(m+n)
// SC: O(n)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mpp;
        for(auto i: magazine){
            mpp[i]++;
        }
        for(auto i: ransomNote){
            if(mpp[i]<=0) return false;
            mpp[i]--;
        }
        return true;
    }
};

