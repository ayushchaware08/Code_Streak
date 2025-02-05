// binary search
// O(log(min(m, n)))

// better one
//TC: o(n+m)
// SC: O(1)
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1=a.size(), n2=b.size();
        
        int cnt=0;
        int i =0, j =0, kele =0;
        while(i<n1 && j<n2){
            cnt++;
            if(a[i]<b[j]){
                kele = a[i++];
                // if(cnt==k){
                //     return a[i];
                //     break;
                // }
                
            } 
            else{
                kele = b[j++];
            } 
                if(cnt==k){
                    return kele;
                }
            
            
        }
        while(i<n1) 
        {
            cnt++;
            kele = a[i++];
            if(cnt==k){
                return kele;
            }
            
        }
        while(j<n2){
            cnt++;
            kele = b[j++];
            if(cnt==k){
                return kele;
            }
        } 
        
        return kele;
        
        // int n = n1+n2;
        // if(n%2 ==1) return (double)arr[n/2];
        // else return ((double)arr[n/2]+(double)arr[(n/2)-1])/2.0;
    }
};