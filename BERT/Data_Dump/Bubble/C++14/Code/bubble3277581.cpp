#include<bits/stdc++.h>
using namespace std;
int main(){
  int flag=1,i,n,a[100],count=0;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  while(flag){
    flag=0;
    for(i=n-1;i>0;i--){
      if(a[i]<a[i-1]){
	swap(a[i],a[i-1]);
	count++;
	flag=1;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i==n-1)cout<<a[i];
    else cout<<a[i]<<" ";
  }
  cout<<endl;
  cout<<count<<endl;
  return 0;
  
}

