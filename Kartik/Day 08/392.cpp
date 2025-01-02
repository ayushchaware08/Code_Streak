#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isSubsequence(string str, string t)
{
    if (t.length() == 0)
    {
        return 0;
    }
    if (str.length() == 0)
    {
        return 1;
    }
    int s = 0;
    int index = 0;
    char check = str[index];
    int cnt = 0;
    string ans = "";
    while (s < t.length())
    {
        cout << check << " " << t[s] << endl;
        if (t[s] == check)
        {
            cnt++;
            ans += check;
            check = str[++index];
            if (ans == str)
            {
                return 1;
            }
        }

        s++;
    }

    return 0;
}
int main()
{
    string s = "abc", t = "ahbgdc";
    // string s = "axc", t = "ahbgdc";
    // string s = "", t = "ahbgdc";
    cout << isSubsequence(s, t) << endl;
    return 0;
}