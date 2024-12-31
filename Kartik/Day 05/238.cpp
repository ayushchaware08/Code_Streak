#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}
vector<int> productExceptSelf(vector<int> &nums)
{
    int multiply = 1;
    int zeroCnt = 0;
    for (auto i : nums)
    {
        if (i == 0)
        {
            zeroCnt++;
        }
        else
        {

            multiply *= i;
        }
    }
    if (zeroCnt >= 2)
    {
        vector<int> ans(nums.size());
        return ans;
    }
    if (zeroCnt == 1)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[i] = 0;
            }
            else
            {
                nums[i] = multiply;
            }
        }
    }
    else
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = multiply / nums[i];
        }
    }
    return nums;
}
int main()
{
    // vector<int> arr = {1, 2, 3, 4};
    vector<int> arr = {0, 1, 0, 3, -3};
    printArr(productExceptSelf(arr));
    return 0;
}