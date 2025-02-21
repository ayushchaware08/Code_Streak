// o(n+m)
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        for (auto i : nums)
        {
            mpp[i]++;
        }
        for (auto i : mpp)
        {
            if (i.second == 1)
                return i.first;
        }
        return -1;
    }
};