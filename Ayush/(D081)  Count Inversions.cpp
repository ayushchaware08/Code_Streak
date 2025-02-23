// optimal one - modyfied merge sort
// TC: o(n log n)
// SC: o(n)

// Brute force
// TC:o(n^2)
// SC: o(1)
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    int cnt =0;
    for(int i=0; i<n; i++){
        for(int j =i+1; j<n; j++){
            if(arr[i]>arr[j]) cnt++;
        }
    }
    return cnt;
}