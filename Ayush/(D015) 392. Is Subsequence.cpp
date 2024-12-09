// TC = O(t)
// SC = O(1)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int start_s = 0, start_t = 0;
        while(start_t < t.length() && start_s <s.length()){
            if(s[start_s] == t[start_t]){
                start_s++;
            }
            start_t++;
        }
        return start_s == s.length();
    }
};
