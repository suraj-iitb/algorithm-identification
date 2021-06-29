#include<iostream>
#include<vector>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;

int main() {
  int n; cin>>n;
  vector<int> a(n);
  rep(i, n) cin>>a[i];

  bool frag=true;
  int p=0; //未ソート部分の先頭
  int cnt=0;
  while (frag) {
    frag=false;
    for (int i=n-1; i>p; i--) {
      if (a[i]<a[i-1]) {
        int tmp=a[i-1];
        a[i-1]=a[i];
        a[i]=tmp;
        frag=true;
        cnt++;
      }
    }
    p++;
  }
  rep(i, n-1) cout<<a[i]<<" ";
  cout<<a[n-1]<<endl;
  cout<<cnt<<endl;
  return 0;
}
