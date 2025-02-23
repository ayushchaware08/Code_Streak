// Optimal one 
// TC: O(2n)
// SC: O(1)
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // max celeb  = 1, min celeb = 0;
        int n = mat.size();
        int celeb =0;
        
        // can be celeb
        for(int i =0; i<n; i++){
            if(mat[celeb][i]==1) celeb=i; // celeb know i
        }
        
        for(int i=0; i<n; i++){
            if(i!=celeb){ // non-diagonal
                // checking each column and row
                if(mat[celeb][i] == 1 || mat[i][celeb]==0){ // youknow, but i dont
                    return -1;
                }   
            } 
        }
        return celeb;
    }
};


// brute
// TC: O(n*n) + o(n)
// sc: o(2n)
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size(); // row
        vector<int> knowMe(n,0);
        vector<int> iKnow(n,0);
        //it can be either one celebrity or no celebrity
        for(int i=0; i<n; i++){
            for(int j =0; j<n; j++){
                if(mat[i][j] == 1){
                    knowMe[j]++;
                    iKnow[i]++;
                }
            }   
        }
        // celeb condition
        for(int i =0; i<n; i++){
            if(knowMe[i]==n-1 && iKnow[i]==0) return i;
        }
        return -1;
    }
};