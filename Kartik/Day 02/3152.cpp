#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArr(vector<bool> arr)
{
    for (auto i : arr)
    {
        i ? cout << "true" : cout << "false";
        cout << ' ';
    }
    cout << endl;
}

bool checkOpp(int x, int y)
{
    int a, b;
    bool check = 1;
    if (x & 1)
    {
        check = 0;
        a = x;
        b = y;
    }
    if (y & 1)
    {
        check = 0;
        a = y;
        b = x;
    }
    if (check)
    {
        return 0;
    }
    return (b & 1) ? 0 : 1;
}
vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
{
    vector<bool> ans;
    vector<int> mapping(nums.size());

    for (int i = 0; i < queries.size(); i++)
    {
        int s = queries[i][0];
        int e = queries[i][1];

        bool verify = 1;
        for (int j = s; j < e; j++)
        {
            bool x = checkOpp(nums[j + 1], nums[j]);
            if (!x)
            {
                verify = 0;
                ans.push_back(x);
                break;
            }
        }
        if (verify)
        {
            ans.push_back(1);
        }
    }
    return ans;
}

int main()
{

    // vector<int> nums = {1, 4};
    // vector<vector<int>> queries = {{0, 1}};

    vector<int> nums = {4, 3, 1, 6};
    vector<vector<int>> queries = {{0, 2}, {2, 3}};

    printArr(isArraySpecial(nums, queries));
    return 0;
}