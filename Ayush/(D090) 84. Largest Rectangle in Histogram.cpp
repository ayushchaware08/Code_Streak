// optimal one - in single pass
// TC: o(n) + o(n)
// sc:o(n)

// BEtter one - multiple passes
// TC: O(n)+o(n)+o(n).. = o(n) approx.
// SC: o(n)
#include<bits/stdc++.h>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> lsmall(n), rsmall(n);
        // for left small ele array
        for(int i =0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            // if(st.empty()) lsmall[i] =0;
            // else lsmall[i] = st.top()+1;
            lsmall[i] = st.empty()? 0: st.top()+1;
            st.push(i);
        }
        // reuse the same stack
        while(!st.empty()) st.pop();
        // right half
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            // if(st.empty()) rsmall[i] =n-1;
            // else rsmall[i] = st.top()-1;
            rsmall[i]=st.empty()? n-1:st.top()-1 ;
            st.push(i);
        }

        int maxx=0;
        for(int i =0; i<n; i++){
            maxx = max(maxx, heights[i]*(rsmall[i]-lsmall[i]+1));
        }
        return maxx;
    }
};


// Brute Force
// TC: o(n^2) - TLE
// SC: o(1)
#include<bits/stdc++.h>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        for(int i =0; i<heights.size(); i++){
            int minHeight = INT_MAX;
            for(int j =i; j<heights.size(); j++){
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea, minHeight*(j-i+1));
            }
        }
        return maxArea;
    }
};