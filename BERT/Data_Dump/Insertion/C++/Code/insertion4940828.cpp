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
  for(int i=0;i<n;i++){
    int v=a[i];
    int j=i-1;
    while(j>=0 && v<a[j]){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    rep(i,n){
      if(i!=n-1)
        cout<<a[i]<<" ";
      if(i==n-1)
        cout<<a[i]<<endl;
    }
  }
}
