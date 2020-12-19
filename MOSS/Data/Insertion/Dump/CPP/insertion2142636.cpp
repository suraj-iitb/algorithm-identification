#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=1;i<=n;i++){
    
    for(int j=0;j<n;j++){
      cout<<a[j];
      if(j!=n-1)cout<<" ";
    }cout<<endl;
    
    for(int j=0;j<i;j++){
      if(a[i-j-1]>a[i-j])swap(a[i-j-1],a[i-j]);
      else break;
    }

  }
  return 0;
}
