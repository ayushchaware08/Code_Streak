// BS
// TC: o(log2(m*10)) * o(n)
// SC: o(1)
#include<bits/stdc++.h>
int multiply(int num, int n, int m){
  long long ans = 1.0;
  for(int i=1; i<=n; i++){
    ans = ans*num;
    if(ans>m) return 2;
  }
  if(ans == m) return 1;
  return 0;
}
int NthRoot(int n, int m) {
  if(n<=0 || m<0) return -1;
  if(m==0) return 0;

  int low =1, high =m;
  // double eps= 1e-6;
  while(high>=low){
    int mid = (low+high)/2.0;
    int mul = multiply(mid,n,m);
    if(mul==1) return mid;
    else if(mul==0) low=mid+1;
    else high =mid-1;
  }
  return -1;
}