#include <bits/stdc++.h>
#include <iostream>
using namespace std;

char toLower(char ch)
{
    if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
    {
        return ch;
    }
    return ch - 'A' + 'a';
}

bool isPalindrome(string s)
{
    string toCheck = "";
    for (auto i : s)
    {
        if (i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z' || i >= '0' && i <= '9')
        {
            toCheck += toLower(i);
        }
    }
    int start = 0, end = toCheck.length() - 1;
    while (end >= start)
    {
        if (toCheck[start++] != toCheck[end--])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    // string s = "A man, a plan, a canal: Panama";
    // string s = "race a car";
    string s = " ";
    cout << isPalindrome(s) << endl;

    return 0;
}