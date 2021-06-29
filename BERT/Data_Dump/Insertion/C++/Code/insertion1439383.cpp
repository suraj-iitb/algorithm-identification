#include<bits/stdc++.h>
using namespace std;
main(){
  int A[1050];
  int n;
  int j;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  for(int i=1;i<n;i++){
    int v=A[i];
    for(j=0;j<n;j++){
      cout<<A[j];
      if(j!=n-1){
	cout<<" ";
      }
      else{
	cout<<"\n";
      }
    }
    for(j=i-1;j>=0&&A[j]>v;j--){
      A[j+1]=A[j];
    }
    A[j+1]=v;
  }
  for(j=0;j<n;j++){
    cout<<A[j];
    if(j!=n-1){
      cout<<" ";
    }
    else{
      cout<<"\n";
    }
  }
}
