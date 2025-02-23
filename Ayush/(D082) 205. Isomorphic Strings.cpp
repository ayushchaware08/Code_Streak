// optimized

//Brute force
// TC: o(n)
// SC: (1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int>smpp;
        unordered_map<char, int>tmpp;
        for(int i =0; i<s.length(); i++){
            // check char in s
            if(smpp.find(s[i])==smpp.end()){
                smpp[s[i]]=i;
            }
            // chack char in t
            if(tmpp.find(t[i])==tmpp.end()){
                tmpp[t[i]]=i;
            }
            // compare indices of both str
            if(smpp[s[i]]!=tmpp[t[i]]) return false;
        }
        return true;

    }
};
