// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
// TC = O(k) -- k=no of cards
// SC = O(1)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       
        int lsum = 0, rsum = 0, maxpnt = 0;
        for(int i = 0; i<k; i++){
            lsum += cardPoints[i];
        }
            maxpnt = lsum;
        int rindex = cardPoints.size()-1;
        for(int i = k-1; i>=0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rindex];
            rindex--;
            maxpnt = max(maxpnt, lsum+rsum);
        }
        return maxpnt;
    }
};
