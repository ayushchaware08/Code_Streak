#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int strStr(string haystack, string needle)
{
    return haystack.find(needle);
}
int main()
{
    // string haystack = "sadbutsad", needle = "sad";
    string haystack = "leetcode", needle = "leeto";

    cout << strStr(haystack, needle);
    // Output: 0*/
    // Output: -1*/

    return 0;
}