#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// not done

pair<int, int> getMAx(vector<int> arr, int s, int e)
{
    int maxi = 0;
    pair<int, int> ans = {maxi, s};
    for (int i = s + 1; i < s + e; i++)
    {
        if (arr[i] >= maxi)
        {
            ans.first = arr[i];
            ans.second = i;
        }
    }
    return ans;
}

int jump(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return 0;
    }
    int n = nums.size();
    int cnt = 0;
    int currIndex = 0;
    int possibleMoves = nums[currIndex];
    if (possibleMoves >= n - 1)
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        cnt++;
        pair<int, int> move = getMAx(nums, currIndex, possibleMoves);
        if (currIndex + possibleMoves >= n - 1)
        {
            return cnt;
        }

        currIndex = move.second;
        possibleMoves = move.first;
    }
    return cnt;
}
int main()
{
    // vector<int> arr = {2, 3, 0, 1, 4};
    // vector<int> arr = {1, 2};
    // vector<int> arr = {2, 3, 1, 1, 4};
    vector<int> arr = {1, 1, 1, 1};
    cout << jump(arr) << endl;
    return 0;
}