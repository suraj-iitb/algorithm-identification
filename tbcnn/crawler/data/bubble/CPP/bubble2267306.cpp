#include <bits/stdc++.h>
#define N 110
using namespace std;

int main(){
  int n;
  cin>>n;
  int A[N],cnt=0;
  for(int i=0;i<n;i++)cin>>A[i];

  for(int i=0;i<n-1;i++)
    for(int j=n-1;j>=i+1;j--)
      if(A[j] < A[j-1]) swap(A[j],A[j-1]),cnt++;

  for(int i=0;i<n;i++){
    if(i)cout<<" ";
    cout<<A[i];
  }
  cout<<endl;
  cout<<cnt<<endl;

  return 0;
}
