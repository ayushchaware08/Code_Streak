#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int curr = nums[0];
    int index = 1;
    int subCnt = 1;
    int cnt = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != curr)
        {
            curr = nums[i];
            subCnt = 1;
            cnt++;
            nums[index++] = nums[i];
        }
        else if (nums[i] == curr && subCnt < 2)
        {
            nums[index++] = nums[i];
            curr = nums[i];
            subCnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    cout << removeDuplicates(arr);
    return 0;
}