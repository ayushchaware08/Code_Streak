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

vector<int> twoSum(vector<int> &arr, int target)
{
    int i = 0;
    int j = arr.size() - 1;
    while (j > i)
    {
        int sum = arr[i] + arr[j];
        if (sum == target)
        {
            return {i + 1, j + 1};
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return {-1, -1};
}
int main()
{
    // vector<int> numbers = {2, 7, 11, 15};
    // int target = 9;

    // vector<int> numbers = {0, 0, 3, 4};
    // int target = 0;

    // vector<int> numbers = {2, 3, 4};
    // int target = 6;

    // vector<int> numbers = {-1, 0};
    // int target = -1;

    vector<int> numbers = {5, 25, 75};
    int target = 100;

    printArr(twoSum(numbers, target));

    return 0;
}