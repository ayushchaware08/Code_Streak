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
void rotate(vector<int> &nums, int k)
{
    vector<int> temp = nums;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        nums[(i + k) % n] = temp[i];
    }
}
int main()
{
    vector<int> arr = {-1, -100, 3, 99};
    int k = 2;
    rotate(arr, k);
    printArr(arr);
    return 0;
}