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

int removeDuplicates(vector<int> &nums)
{
    int cnt = 1;
    int curr = nums[0];
    int index = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (curr != nums[i])
        {
            cnt++;
            nums[index++] = nums[i];
            curr = nums[i];
        }
    }
    return cnt;
}
int main()
{
    // vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums = {1, 1, 2};
    int x = removeDuplicates(nums);
    cout << x << endl;
    printArr(nums, x);
    return 0;
}