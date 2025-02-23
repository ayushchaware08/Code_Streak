// Binary approach o(logn)
class Solution
{
public:
    bool binarysearch(vector<int> &nums, int key)
    {
        int s = 0, e = nums.size() - 1;
        while (e >= s)
        {
            int mid = (e + s) / 2;
            if (nums[mid] == key)
                return true;
            else if (nums[mid] < key)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return false;
    }
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= n; i++)
        {
            // if(find(nums.begin(), nums.end(), i)==end(nums)) ans.push_back(i);
            if (binarysearch(nums, i) == 0)
                ans.push_back(i);
        }
        return ans;
    }
};

// Linear approach - TLE
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 1; i <= n; i++)
        {
            if (find(nums.begin(), nums.end(), i) == end(nums))
                ans.push_back(i);
        }
        return ans;
    }
}; 
