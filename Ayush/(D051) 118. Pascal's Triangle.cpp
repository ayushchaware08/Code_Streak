
// Q1-> Print the ele at Perticular r and c 
// extreame Brute Force 
// TC: O(r)
// SC: O(1)
int nCr(int n,  int r){
    long long res =1;
    for(int i=0; i<r;  i++ ){
        // n-i will be factorial of n till c times
        // then / by i+1 (aas per formula)
        res= res * (n-i);
        res = res/(i+1);
    }
    return res;
}

// Q2-> print nth row of pascal Triangle
    vector<int> generateRow(int row){
        long long ans =1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col = 1; col<row; col++){
            ans = ans*(row-col);
            ans = ans/col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

// Q3 -> Print Entire Pascal triangle
// prv: o(n*n*r) using nrc 
// TC: O(n^2) using generateRow
// SC: O(1)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        // building pascal triangle
        for(int row=1; row<=numRows; row++){

            // vector<int> temp;
            // for(int col=1; col<=row;col++){
            //     temp.push_back(nCr(row-1, col-1));
            // }
            // ans.push_back(temp);

            ans.push_back(generateRow(row));
        } 
        return ans;
    }
