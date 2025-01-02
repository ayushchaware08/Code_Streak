#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int stringToBinary(string str1, string str2)
{
    int left = 0, right = 0;
    for (auto i : str1)
    {
        if (i == '0')
        {
            left++;
        }
    }
    for (auto i : str2)
    {
        if (i == '1')
        {
            right++;
        }
    }
    return left + right;
}

int maxScore(string s)
{
    int cnt = s.length();
    int ans = INT_MIN;
    for (int i = 1; i < cnt; i++)
    {
        string str2 = s.substr(i, cnt);
        string str1 = s.substr(0, cnt - str2.length());

        ans = max(ans, stringToBinary(str1, str2));
    }
    return ans;
}
int main()
{
    // string s = "1111";
    // string s = "00111";
    string s = "011101";
    cout
        << maxScore(s);
    return 0;
}