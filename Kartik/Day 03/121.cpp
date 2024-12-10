#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
void getMaximum(vector<int> arr, vector<int> &ans)
{
    int maxi = -1;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int temp = arr[i];
        ans[i] = maxi;
        maxi = max(maxi, temp);
    }
}

int maxProfit(vector<int> &prices)
{
My solution
    int maxi = 0;
    vector<int> arr(prices.size());
    getMaximum(prices, arr);
    for (int i = 0; i < prices.size(); i++)
    {
        if (arr[i] != -1)
        {
            maxi = max((arr[i] - prices[i]), maxi);
        }
    }
    return maxi;
}
*/
int maxProfit(vector<int> prices)
{
    // O(1) approach used with help of Leetcode
    int profit = 0;
    int buy = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        if (buy < prices[i])
        {
            int x = prices[i] - buy;
            if (x > profit)
            {
                profit = x;
            }
        }
        else
        {
            buy = prices[i];
        }
    }
    return profit;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(arr) << endl;
    return 0;
}