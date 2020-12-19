#include<bits/stdc++.h>
using namespace std;
int main(){ 
  int n,flag=0;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++){
    for(int j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
	swap(a[j],a[j-1]);
	flag++;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(i==n-1)cout<<a[i]<<endl;
    else cout<<a[i]<<" ";
  }
  cout<<flag<<endl;
  return 0;
}
