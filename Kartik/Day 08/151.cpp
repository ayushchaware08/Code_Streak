#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string reverseWords(string str)
{
    stack<string> st;
    int s = 0, cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (cnt == 0 && str[i] == ' ')
        {
            s = i + 1;
            continue;
        }
        if (str[i] == ' ' || i == str.length() - 1)
        {

            if (i == str.length() - 1 && str[i] != ' ')
            {
                st.push(str.substr(s, cnt + 1));
            }
            else
            {
                st.push(str.substr(s, cnt));
            }
            s = i + 1;
            cnt = 0;
            continue;
        }
        cnt++;
    }
    string ans = "";
    while (!st.empty())
    {
        string top = st.top();
        st.pop();
        ans += top;
        if (!st.empty())
        {
            ans += ' ';
        }
    }
    return ans;
}
int main()
{
    // string s = "  hello world  ";
    // string s = "the sky is blue";
    // string s = "a good example ";
    string s = "the sky is 12s";
    cout << reverseWords(s) << endl;
    return 0;
}