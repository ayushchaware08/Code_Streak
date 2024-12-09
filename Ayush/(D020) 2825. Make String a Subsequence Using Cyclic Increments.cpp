// Two pointer approach
// TC: O(n+m) str1 and str2
// SC: O(1)

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int str2Index = 0;
        int lenstr1 = str1.size(), lenstr2=str2.size();
        for(int str1Index=0; str1Index<lenstr1 && str2Index<lenstr2; ++str1Index){
            // direct match || next letter case ||  wrap around case z->a 
            if(str1[str1Index]==str2[str2Index] || 
                (str1[str1Index]+1 == str2[str2Index]) ||
                (str1[str1Index] -25 == str2[str2Index])){
                    str2Index++;
            }
        }
        // str2 get traverse completely i.e true
        return str2Index == lenstr2;
    }
};
