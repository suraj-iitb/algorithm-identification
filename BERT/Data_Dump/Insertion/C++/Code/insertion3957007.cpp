#include<iostream>
#include<vector>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;

int main() {
  int n; cin>>n;
  vector<int> a(n);
  rep(i, n) cin>>a[i];

  rep(i, n) {
    if (i==0) {
      rep(x, n-1) cout<<a[x]<<" ";
      cout<<a[n-1]<<endl;
      continue;
    }
    int v=a[i];
    int j=i-1;
    while (j>=0&&a[j]>v) {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    rep(x, n-1) cout<<a[x]<<" ";
    cout<<a[n-1]<<endl;
  }
  return 0;
}
