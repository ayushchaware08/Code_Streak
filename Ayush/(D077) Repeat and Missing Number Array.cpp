// Link: https://www.naukri.com/code360/problems/missing-and-repeating-numbers_873366?leftPanelTabValue=SUBMISSION

// Optimal (XOR) - avoid in interview
// TC: O(n)
// SC: O(1)

// Optimal (mathamatics) - Recomended in Interview
// TC: O(n)
// SC: O(1)
#include <bits/stdc++.h>
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// S(arr) - S(n)  (s-sn)
	// S(arr^2)- S(n^2)  (s-s2n)
	long long SN = (n * (n+1)) / 2;
	long long S2N = (n * (n+1)* (2*n+1)) / 6;

	long long S =0, S2 =0;

	for(int i =0; i<n; i++){
		S+= arr[i];
		S2 += (long long) arr[i] * (long long) arr[i];
	}

	long long val1 = S-SN; //  x-y eq1
	long long val2 = S2-S2N; // x^2 - y^2 eq2

	val2 = val2/val1; // x+y
	long long x = (val1+val2)/2;
	long long y = x-val1;

	return make_pair((int) y, (int)x);
}

// Hashing using array
// TC: O(2n)
// SC: O(n)
#include <bits/stdc++.h>
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int hash[n+1] = {0};
	for(int i =0; i<n; i++){
		hash[arr[i]]++;
	}
	int missing =-1, repeat=-1;

	for(int i=1; i<=n; i++){
		if(hash[i]==2) repeat =i;
		else if(hash[i]==0) missing =i;

		if(missing!=-1 && repeat!=-1){
			break;
		}
	}
	return { missing, repeat};
	
}


// Brute Forrce
// frequency check 0 i.e missing number and 2 i.e repeated number
// o(n^2) O(1)

