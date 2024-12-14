class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt =0, end = s.size()-1;
        // traverse all " "
        while(end>=0 && s[end]==' '){
            end--;
        }
        // now cnt the len og last
        while(end>=0 && s[end]!=' '){
            cnt++;
            end--;
        }
        return cnt;
    }
};