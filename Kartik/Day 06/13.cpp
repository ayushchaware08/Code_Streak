#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int romanToInt(string s)
{
    int ans = 0;
    vector<int> mapping = {1, 5, 10, 50, 100, 500, 1000};
    char curr = s[0];
    for (int i = 0; i < s.length(); i++)
    {
        int cnt = 0;
    }
}
int main()
{
    string s = "III";
    cout << romanToInt(s) << endl;
    return 0;
}