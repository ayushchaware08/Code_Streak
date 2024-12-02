// OPTIMIZED Approach
// TC: o(1)
// SC: o(1)

class Solution {
public:
    string intToRoman(int num) {
        string roman_ans = "";

        // hashmap to store roman
        vector<pair<int, string>> int_roman = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},{100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},{10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        for(int i =0; i<int_roman.size();i++ ){
            while(num >= int_roman[i].first){
                // roman letter added
                roman_ans += int_roman[i].second;
                // numm reduced as per addtion 
                num -= int_roman[i].first;
            }
        }
        return roman_ans;
    }
};
