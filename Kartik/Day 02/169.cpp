#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int mid = nums.size() / 2;
    unordered_map<int, int> mapping;
    for (auto i : nums)
    {
        mapping[i]++;
        if (mapping[i] > mid)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(arr) << endl;
    return 0;
}