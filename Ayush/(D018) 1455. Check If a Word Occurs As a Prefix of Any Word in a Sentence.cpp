// TC: O(n)
// SC: O(1)

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int currWordPosn =1, i=0, n=sentence.length();

        while(i<n){
            //space char
            while(i<n && sentence[i]==' '){
                currWordPosn++;
                i++;
            }
            int j =0;
            // non-space char compare it -> word is matching
            while(i<n && j<searchWord.length()&&sentence[i]==searchWord[j]){
                i++;
                j++;
            }
            // found
            if(j==searchWord.length()) return currWordPosn;
            // frwd till  till ' ' not matched str
            while(i<n && sentence[i] != ' ') i++;
        }
        return -1;
    }
};
