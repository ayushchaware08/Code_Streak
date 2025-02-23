// better one
// O(n^2)
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int maxlen =0;
        unordered_map<int, int> mpp; // sum and index
        int sum = 0;
        
        for(int i =0; i<arr.size(); i++){
            sum += arr[i];
            if(sum ==0) maxlen = i+1;
            else if(mpp.find(sum) != mpp.end()) maxlen = max(maxlen, i-mpp[sum]);
            else mpp[sum] =i;
        }
        
        return maxlen;
    }
};

// brute - TLE
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int maxlen =0;
        int sum =0;
        for(int i =0; i<arr.size(); i++){
            sum =0;
            for(int j =i; j<arr.size(); j++){
                sum += arr[j];
                if(sum ==0){
                    maxlen = max(maxlen, j-i+1);
                    // break
                }
            }
        }
        return maxlen;
    }
};