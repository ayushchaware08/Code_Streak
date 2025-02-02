
// Better one
//TC: O(n+m)
// sc: o(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;

        int index=n/2;
        int index1=index-1;
        int cnt=0;
        int ind1e1=-1, ind2e1=-1;

        // merge
        int i=0, j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==index) ind1e1 = nums1[i];
                if(cnt==index1) ind2e1 = nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt==index) ind1e1 = nums2[j];
                if(cnt==index1) ind2e1 = nums2[j];
                cnt++;
                j++;
            }
        }

        // left out ele
        while (i < n1) {
            if (cnt == index) ind1e1=nums1[i];
            if (cnt == index1) ind2e1=nums1[i];
            cnt++;
            i++;
        }
        while (j < n2) {
            if (cnt==index) ind1e1=nums2[j];
            if (cnt==index1) ind2e1=nums2[j];
            cnt++;
            j++;
        }
        // median
        if (n%2 == 1) return (double)ind1e1;
        return (double) ((double)(ind1e1+ind2e1))/2.0;
    }
};