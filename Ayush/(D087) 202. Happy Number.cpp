// space can br optimized by Two opinter approach( having slow ptr and fast ptr)

// Use hash map 
// TC: o(log n)
// SC: o(unique n)

class Solution {
    int getNextNum(int n){
        int num =0;
        while(n>0){
            int digit = n% 10; // last digit
            num += digit* digit;
            n = n / 10; // removed ones place
        }
        return num;
    }
public:
    bool isHappy(int n) {
        // keep track visited number. if found same i.e infinite cycle
        unordered_set<int> mpp;
        while(mpp.find(n)==mpp.end()){
            mpp.insert(n);
            n = getNextNum(n);
            if(n==1) return true;
        }
        return false;
    }
};