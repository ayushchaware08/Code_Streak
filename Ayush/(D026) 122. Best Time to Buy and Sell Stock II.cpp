//optimized

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=1, curr_p, max_p =0;

        while(sell<prices.size()){
            curr_p = prices[sell] - prices[sell-1];
            if(prices[sell]>prices[sell-1]){ // in profit
                max_p += curr_p;
            }
            sell++;
        }
        return max_p;
    }
};
