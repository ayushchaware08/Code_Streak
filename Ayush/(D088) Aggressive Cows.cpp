// Binary Search
// TC: o(nlogn)+o(n* log(max-min))
// sc: o(1)

class Solution {
    bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size();
    int cntCows = 1; // track of placed cows
    int last = stalls[0]; 
    for (int i=1;i<n;i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place cow.
            last = stalls[i];
        }
        if (cntCows >= cows) return true;
    }
    return false;
    }
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls[n-1] - stalls[0];
        while(low<=high){
            int mid = (low+high)/2;
            if(canWePlace(stalls, mid, k)==true) low = mid+1;
            else high = mid -1;
        }
        return high;
    }
};

// Linear Search
// TC: o(nlogn) + O(max-min)
// SC:o(1)
class Solution {
    bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size();
    int cntCows = 1; // track of placed cows
    int last = stalls[0]; 
    for (int i=1;i<n;i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place cow.
            last = stalls[i];
        }
        if (cntCows >= cows) return true;
    }
    return false;
    }
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int limit = stalls[n-1] - stalls[0];// range max - min
        for(int i =0; i<=limit; i++){
            if(canWePlace(stalls, i, k) == false) return (i-1);
        }
        return limit;
    }
};