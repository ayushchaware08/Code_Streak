#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int getCnt(vector<int> arr, int x)
{
    int cnt = 0;
    for (auto i : arr)
    {
        if (i >= x)
        {
            cnt++;
        }
    }
    return cnt;
}

int hIndex(vector<int> &arr)
{
    if (arr.size() == 1)
    {
        return 1;
    }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int x = i + 1;
        int cnt = getCnt(arr, x);
        if (cnt >= x)
        {
            return x;
        }
    }

    return 0;
}
int main()
{
    vector<int> arr = {1, 3, 1};
    // vector<int> arr = {3, 0, 6, 1, 5};
    // vector<int> arr = {123, 123};
    // vector<int> arr = {123};
    cout << hIndex(arr) << endl;
    return 0;
}