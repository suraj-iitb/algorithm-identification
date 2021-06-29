#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  int n;
  cin>>n;
  vector<int>a(n);
  rep(i,n)
    cin>>a[i];
  int ans=0;
  for(int i=0;i<n;i++){
    int minv=i;
    for(int j=i+1;j<n;j++){
      if(a[minv]>a[j])
        minv=j;
    }
    if(minv!=i){
      swap(a[i],a[minv]);
      ans++;
    }
  } 
  rep(i,n){
    if(i<n-1)
      cout<<a[i]<<" ";
    else
      cout<<a[i]<<endl;
  }
  cout<<ans<<endl;
}
