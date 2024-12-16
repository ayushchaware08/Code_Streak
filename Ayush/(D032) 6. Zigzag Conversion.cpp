// TC SC : o(n)
class Solution {
public:
    string convert(string s, int numRows) {
        // to handle <1row
        if(numRows==1) return s;
        // creating seperate storage for each row
        vector<string>row(numRows, "");

        int curr_row =0, direction=-1;
        for(int i=0; i<s.length();i++){
            //revrese direction
            if(curr_row == numRows-1 || curr_row==0) direction*=(-1);

            row[curr_row]+=s[i];

            if(direction ==1) curr_row++; //down
            else curr_row--; //up
        }
        string result;
        // loop through each row and append
        for(auto& it:row){
            result+=it;
        }
        return result;
    }
};