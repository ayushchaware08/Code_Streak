// o(log n) Binary search approach


// o(root n)
class Solution
{
public:
    int arrangeCoins(int n)
    {
        int i = 1;
        while (n > 0)
        {
            // if(n>i){
            i++;
            n = n - i;
            // }
        }

        return i - 1;
    }
};