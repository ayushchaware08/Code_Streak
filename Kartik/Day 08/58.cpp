#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int lengthOfLastWord(string str)
{
    int e = str.length() - 1;
    int cnt = 0;
    while (e >= 0)
    {
        if (str[e] >= 'A' && str[e] <= 'Z' || str[e] >= 'a' && str[e] <= 'z')
        {
            cnt++;
        }
        if (cnt != 0 && str[e] == ' ')
        {
            return cnt;
        }
        e--;
    }
    return -1;
}
int main()
{

    // string s = "   fly me   to   the moon  ";
    string s = "luffy is still joyboy";
    // string s = "Hello World";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}