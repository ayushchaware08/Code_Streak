#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long pickGifts(vector<int> &gifts, int k)
{
    priority_queue<int> pq;
    for (auto i : gifts)
    {
        pq.push(i);
    }
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        int x = floor(sqrt(pq.top()));
        pq.pop();
        pq.push(x);
    }

    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }

    return ans;
}
int main()
{
    vector<int> arr = {1, 1, 1, 1};
    int k = 4;
    cout << pickGifts(arr, k);
    return 0;
}