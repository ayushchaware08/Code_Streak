// optimal - hash table
// o(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpp;
        for(auto it: s){
            mpp[it]++;
        }
        for(auto it: t){
            mpp[it]--;
        }

        for(auto it: mpp){
            if(it.second !=0) return false;
        }
        return true;
    }
};

// Sorting
// o(nlogn)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};