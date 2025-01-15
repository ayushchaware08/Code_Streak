// Google
// Combinatorial Formula - Optimal
// TC: O(min(m,n))
// SC: O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        // total direction
        int N = n+m-2; // no of moves to reach end 
        int r = n-1; // necessary down moves
        double res =1;
        for(int i=1; i<=r;  i++ ){
            res= res * (N-r+i)/i;
        }
        return (int)res;
    }
};

// Dynamic Programming
// TC: O(n*m) quadratic complixity
// SC: O(n*m)

// Brute Force - Recursion - TLE
// TC: 2^(m+n)
// SC: 
class Solution {
public:
    int countPath(int i, int j, int n, int m){
        if(i==(n-1) && j==(m-1)) return 1;
        if(i>=n || j>=m) return 0;
        else return countPath(i+1,j,n,m)+countPath(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) {
        return countPath(0,0,m,n);
    }
};