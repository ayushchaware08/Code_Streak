#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    for (int i = 0; i < strs[0].length(); i++)
    {
        char check = strs[0][i];
        for (auto j : strs)
        {
            if (j.length() >= i && j[i] != check)
            {
                return ans;
            }
        }
        ans += check;
    }
    return ans;
}
int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    // vector<string> strs = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}