#include<bits/stdc++.h>
using namespace std;
#define N 100

int main(){
  int i,j,n,v,r,A[N];
  cin >> n;

  for(i=0;i<n;i++)cin >> A[i];
  for(i=0;i<n;i++){
    if(i!=n-1)cout << A[i] << ' ';
    else cout << A[i] << endl;
  }
  
  for(i=1;i<n;i++){
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }

    for(r=0;r<n;r++){
	if(r!=n-1)cout << A[r] << ' ';
	else cout << A[r] << endl;
      }
    
  }


  return 0;
}


