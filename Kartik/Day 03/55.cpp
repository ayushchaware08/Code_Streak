#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool solve(vector<int> arr, int &index, int &prevIndex, int target)
{
    bool ans = 0;
    for (; index >= 0; index--)
    {
        if (arr[index] + index >= target)
        {
            target = index;
            ans = 1;
        }
        else
        {
            ans = 0;
        }
    }
    return ans;
}

bool canJump(vector<int> &nums)
{
    int index = nums.size() - 2;
    int target = nums.size() - 1;
    int PrevIndex = nums.size() - 1;
    return solve(nums, index, PrevIndex, target);
}
int main()
{
    // vector<int> arr = {2, 3, 1, 1, 4};
    // vector<int> arr = {3, 2, 1, 0, 4};
    vector<int> arr = {2, 0, 0};
    canJump(arr) ? cout << "True" : cout << "False";
    cout << endl;
    return 0;
}