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
  bool flag=true;
  int i=0;
  int ans=0;
  while(flag){
    flag=false;
    for(int j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
        swap(a[j],a[j-1]);
        flag=true;
        ans++;
      }
    }
    i++;
  }
  rep(i,n){
    if(i<n-1)
      cout<<a[i]<<" ";
    else
      cout<<a[i]<<endl;
  }
  cout<<ans<<endl;
}
