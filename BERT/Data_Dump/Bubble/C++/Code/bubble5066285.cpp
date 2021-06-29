#include <bits/stdc++.h>
using namespace std;

int main(){
  int i,j,n,A[100],ans,cnt=0;
  cin >> n;
  for(i=0;i<n;i++)cin >> A[i];
  ans=1;
  while(ans){
    ans=0;
    for(i=n-1;i>0;i--)
      if(A[i]<A[i-1]){
	swap(A[i],A[i-1]);
	ans=1;
	cnt++;
      }     
  }

  for(i=0;i<n;i++){
    if(i==n-1)cout << A[i] << endl;
    else cout << A[i] << ' ';
  }
  cout << cnt << endl;
  
  return 0;
}

