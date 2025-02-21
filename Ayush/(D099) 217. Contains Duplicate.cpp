// o(n)
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        for (auto i : nums)
        {
            if (mpp[i] >= 1)
                return true;
            // update map
            mpp[i]++;
        }
        return false;
    }
};

// o(nlogn+n)
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};