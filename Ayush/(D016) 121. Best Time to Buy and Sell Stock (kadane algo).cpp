// can be optimized by Kadane's Algorithm

// TC = O(n)
// SC = o(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 1, curr_profit, max_profit = 0;
        // left ptr (buy) must min and further this right ptr (sell) must be max ele
        while (sell < prices.size()) {
            curr_profit = prices[sell] - prices[buy];
            if (prices[buy] < prices[sell]) { // in profit
                max_profit = max(max_profit, curr_profit);
            } else { // in loss
                buy = sell;
            }
            sell++;
        }
        return max_profit;
    }
};
