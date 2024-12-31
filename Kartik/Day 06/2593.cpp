#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long findScore(vector<int> &nums)
{
    long long ans = 0;
    unordered_map<int, bool> mapping(nums.size());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : nums)
    {
        pq.push(i);
    }
    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        for (int i = 0; i < nums.size(); i++)
        {
            if (!mapping[i] && nums[i] == x)
            {

                ans += x;
                mapping[i - 1] = 1;
                mapping[i + 1] = 1;
                mapping[i] = 1;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {2, 3, 5, 1, 3, 2};
    // vector<int> arr = {2, 1, 3, 4, 5, 2};
    cout << findScore(arr) << endl;

    return 0;
}