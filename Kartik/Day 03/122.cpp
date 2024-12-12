#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void getMapping(vector<int> arr, vector<pair<int, int>> &mapping)
{
    int n = arr.size();
    int maxIndex = -1, maxi = -1;
    mapping[n - 1] = {maxIndex, maxi};
    for (int i = n - 2; i >= 0; i--)
    {
        mapping[i] = {maxIndex, maxi};

        if (arr[i] > maxi)
        {
            maxIndex = i;
        }
        maxi = max(maxi, arr[i]);
    }
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<pair<int, int>> mapping(prices.size());
    getMapping(prices, mapping);
    int maxiProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int profit = mapping[i].second - prices[i];
        if (profit > 0)
        {
            cout << prices[i] << " " << profit << endl;
            for (int j = mapping[i].first + 1; j == 0;)
            {
                profit += mapping[j].second - prices[j];
                maxiProfit = max(profit, maxiProfit);
                j = mapping[j].first + 1;
            }
        }
    }
    return maxiProfit;
}
int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    // vector<int> arr = {7, 6, 4, 3, 1};
    cout << maxProfit(arr) << endl;
    return 0;
}