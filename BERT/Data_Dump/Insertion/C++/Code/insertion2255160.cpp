#include<bits/stdc++.h>
using namespace std;
signed main(){
  int n;
  cin>>n;
  int A[n];
  for(int i=0;i<n;i++) cin>>A[i];
  for(int k=0;k<n;k++) cout<<A[k]<<" \n"[k==n-1];
  for(int i=1;i<n;i++){
    int v=A[i];
    int j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(int k=0;k<n;k++) cout<<A[k]<<" \n"[k==n-1];
  }
  return 0;
}
