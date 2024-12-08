#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArr(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int removeElement(vector<int> &nums, int val)
{
    vector<int> temp;
    int cnt = 0;
    for (auto i : nums)
    {
        if (i == val)
        {
            cnt++;
        }
        else
        {
            temp.push_back(i);
        }
    }

    for (int i = 0; i < temp.size(); i++)
    {
        nums[i] = temp[i];
    }

    return (nums.size() - cnt);
}

int main()
{
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int x = removeElement(nums, val);
    cout << x << endl;
    printArr(nums, x);

    return 0;
}