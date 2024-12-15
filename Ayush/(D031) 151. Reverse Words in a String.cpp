// TC: O(n)
// SC: O(1)
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size(), i=0, l=0, r=0;

        while(i<n){
            // skip spaces
            while(i<n && s[i]==' '){
                i++;
            }
            if(i==n) break;
            // copy char of r position
            while(i<n && s[i]!=' '){
                s[r++]=s[i++];
            }
            // reverse l and r substr
            reverse(s.begin()+l, s.begin()+r);
            // add space
            s[r++]=' ';
            // updation for next window
            l=r;
            i++;
        }
        // remove unecessary, i.e resize
        s.resize(r-1);
        return s;
    }
};