#include<bits/stdc++.h>
using namespace std;
int main(){
   int n,a[100],i,l;

  cin>>n;
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  for(l=0;l<n;l++){
    cout<<a[l];
    if(n-l-1)cout<<" ";
  }
  cout<<endl;
  int k,j;
  for(i=1;i<n;i++){
    k=a[i];
    j=i-1;
    while(k<a[j] && j>=0){
      a[j+1]=a[j];;
      j--;
    }
    a[j+1]=k;
    for(l=0;l<n;l++){
      cout<<a[l];
      if(n-l-1)cout<<" ";
    }
    cout<<endl;
  }

  return 0;
}

  

