// https://www.naukri.com/code360/problems/allocate-books_1090540

// Optimal - Binary search
// TC: o(log(range))  range = sum -maxele +1;
// SC: O(1)
#include<bits/stdc++.h>
int cntStu(vector<int> & arr, int pages){
	int n = arr.size();
	int stu =1;
	long long pageStu = 0;
	for(int i = 0; i<n; i++){

		if(pageStu + arr[i]<=pages) pageStu += arr[i]; // pages to curr stu
		else{
			// next stu
			stu++;
			pageStu = arr[i];
		}
	}
	return stu;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;

	int low = *max_element(arr.begin(), arr.end());
	int high = accumulate(arr.begin(),arr.end(), 0);

	while(low<=high){
		int mid = (low+high)/2;
		int stu = cntStu(arr, mid);
		if(stu > m) low = mid+1;
		else high = mid -1;
	}
	return low;

}

// Brute - linear search
// TC: o(sum - maxele +1) * o(n)
// SC: o(1)
#include<bits/stdc++.h>
int cntStu(vector<int> & arr, int pages){
	int n = arr.size();
	int stu =1;
	long long pageStu = 0;
	for(int i = 0; i<n; i++){

		if(pageStu + arr[i]<=pages) pageStu += arr[i]; // pages to curr stu
		else{
			// next stu
			stu++;
			pageStu = arr[i];
		}
	}
	return stu;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;

	int low = *max_element(arr.begin(), arr.end());
	int high = accumulate(arr.begin(),arr.end(), 0);

	for(int i = low; i<=high; i++){
		if(cntStu(arr, i)==m) return i;
	}
	return low;

}
