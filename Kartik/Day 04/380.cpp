#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#include <bits/stdc++.h>
class RandomizedSet
{
    unordered_map<int, bool> mapping;
    set<int> arr;

public:
    RandomizedSet()
    {
        unordered_map<int, bool> mapping;
        set<int> arr;
    }

    bool insert(int val)
    {
        if (mapping[val])
        {
            return 0;
        }
        mapping[val] = 1;
        arr.insert(val);
        return 1;
    }

    bool remove(int val)
    {
        if (!mapping[val])
        {
            return 0;
        }
        arr.erase(val);
        mapping[val] = 0;
        return 1;
    }

    int getRandom()
    {
        auto it = arr.begin();
        int random = rand() % arr.size();
        advance(it, random);
        return *it;
    }
};
int main()
{
    return 0;
}