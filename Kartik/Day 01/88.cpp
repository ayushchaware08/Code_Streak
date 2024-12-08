#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void merge(vector<int> &arr1, int m, vector<int> &arr2, int n)
{

    vector<int> ans;
    int i = 0, k = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i++]);
        }
        else
        {
            ans.push_back(arr2[j++]);
        }
    }
    while (i < m)
    {
        ans.push_back(arr1[i++]);
    }
    while (j < n)
    {
        ans.push_back(arr2[j++]);
    }
    arr1 = ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    merge(nums1, m, nums2, n);
    printArr(nums1);
    return 0;
}