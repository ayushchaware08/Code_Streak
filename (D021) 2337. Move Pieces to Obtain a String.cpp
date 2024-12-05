// We can use  Queue here
// Two pointer - Optimized
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool canChange(string start, string target) {
        int len_start = start.size();
        int i =0, j=0; // track start and target index
        while(i<len_start || j<len_start){
            // skip _ in start
            while(i<len_start && start[i] == '_'){
                i++;
            }
            // skip _ in target
            while(j<len_start && target[j] == '_'){
                j++;
            }
            // one str get exausted, both then true
            if(i == len_start || j == len_start){
                break;
            }
            // check movements L  R 
            if(start[i] != target[j] || (start[i] == 'L' && i<j)
            || (start[i] == 'R' && i>j) ){
                return false;
            }
            i++;
            j++;
        }
        return i == len_start && j == len_start;
    }
};
