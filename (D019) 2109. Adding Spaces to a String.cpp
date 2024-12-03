// Two pointer Approach
// reduced run time by dynamic or fixed size string ans;
// TC: o(n+m)
// SC: O(1)

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
      
        // run time reduce
        // stringstream ans; // dynamically
        // ans.reserve(s.size()+spaces.size()); // fixed size

        int spaceIndex=0;

        // iterate through string s
        for(int i =0; i<s.size();++i){
            // s[i] = to spaces index
            // add space
            if(spaceIndex<spaces.size() && i == spaces[spaceIndex]){
                ans+=' ';
                ++spaceIndex;
            }
            // continue to add ele from s
            ans+=s[i];
        }
        return ans;
    }
};
