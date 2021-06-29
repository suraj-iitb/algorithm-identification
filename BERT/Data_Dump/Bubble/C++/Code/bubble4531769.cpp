#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,a[100];
  cin>>n;
  for (int i=0;i<n;i++) cin>>a[i];
  int t=0;
  for (int i=0;i<n;i++){
    for (int j=n-1;j>=i+1;j--){
      if (a[j]<a[j-1]) {
        swap(a[j],a[j-1]);
        t++;
    }
   }
    
  }
  for (int i=0;i< n;i++){
    if (i!=n-1)cout<<a[i]<<' ';
    else cout<<a[i]<<endl;
  }
  cout<<t<<endl;
}
