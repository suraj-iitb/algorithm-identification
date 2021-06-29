#include <bits/stdc++.h>
using namespace std;

int main(){
  int i,j,n,minj,A[100],cnt=0;
  cin >> n;
  for(i=0;i<n;i++)cin >> A[i];
  
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++)
      if(A[j]<A[minj])minj=j;
    swap(A[minj],A[i]);
    if(A[i]!=A[minj])cnt++;
    
  }
  

  for(i=0;i<n;i++){
    if(i==n-1)cout << A[i] << endl;
    else cout << A[i] << ' ';
  }
  cout << cnt << endl;
  
  return 0;
}

