#include<bits/stdc++.h>
using namespace std;
int main(){
  int i,j,v,n,a[1000];
  cin>>n;
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  
  for(i=1;i<n;i++){
     for(j=0;j<n;j++){
      if(j==n-1)cout<<a[j];
      else cout<<a[j]<<" ";
    }
    cout<<endl;
    v=a[i];
    j=i-1;
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
  }
  for(j=0;j<n;j++){
    if(j==n-1)cout<<a[j];
    else cout<<a[j]<<" ";
  }
  cout<<endl;
  
  return 0;
}

