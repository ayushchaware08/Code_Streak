#include<string>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // one - to - one
        unordered_map<char, string> mpp;
        unordered_map<string, char> mss;

        string temp ="";
        int idx = 0; // track position of pattern
        int n=s.size();

        for(int i =0; i<=n; i++){
            if(s[i]==' ' || i==n){
                if(idx < pattern.size() && (mpp.find(pattern[idx]) != mpp.end() || mss.find(temp) != mss.end())){
                    // havent exceed pattern, either pattern is allredy mapped
                    if(mpp[pattern[idx]] != temp || mss[temp]!=pattern[idx]) return false;
                }else{
                    mpp[pattern[idx]] = temp; // map patten -> word
                    mss[temp] = pattern[idx]; // map word -> pattern char
                }
                temp ="";
                idx++;
            }
            else{ // next word
                temp += s[i];
            }
        }

        return idx == pattern.size();
    }
};