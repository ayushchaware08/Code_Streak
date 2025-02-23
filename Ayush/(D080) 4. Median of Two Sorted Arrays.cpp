// optimal one
// TC; O(log(min(n1,n2)))
// SC; O(1)

// Better one
//TC: O(n+m)
// sc: o(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;

        int index1=n/2;
        int index2=index1-1;
        int cnt=0; // index tracker
        int ind1e1=-1, ind2e1=-1;

        // merge
        int i=0, j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==index1) ind1e1 = nums1[i];
                if(cnt==index2) ind2e1 = nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt==index1) ind1e1 = nums2[j];
                if(cnt==index2) ind2e1 = nums2[j];
                cnt++;
                j++;
            }
        }

        // left out ele
        while (i < n1) {
            if (cnt == index1) ind1e1=nums1[i];
            if (cnt == index2) ind2e1=nums1[i];
            cnt++;
            i++;
        }
        while (j < n2) {
            if (cnt==index1) ind1e1=nums2[j];
            if (cnt==index2) ind2e1=nums2[j];
            cnt++;
            j++;
        }
        // median
        if (n%2 == 1) return (double)ind1e1;
        return (double) ((double)(ind1e1+ind2e1))/2.0;
    }
};

// Brute Force
// TC: o(n1+n2)
// SC: o(n1+n2)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n1=nums1.size(), n2=nums2.size();
        vector<int> arr;
        int i =0, j =0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]) arr.push_back(nums1[i++]);
            else arr.push_back(nums2[j++]);
        }
        while(i<n1) arr.push_back(nums1[i++]);
        while(j<n2) arr.push_back(nums2[j++]);
        
        int n = n1+n2;
        if(n%2 ==1) return (double)arr[n/2];
        else return ((double)arr[n/2]+(double)arr[(n/2)-1])/2.0;
    }
};