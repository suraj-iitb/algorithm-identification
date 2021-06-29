#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(j,n) {
      if(j != n-1) {
        cout << a[j] << ' ';
      }else{
        cout << a[j] << endl;
      }
    }
  for(int i = 1; i < n; i++) {
    int v = a[i];
    int j = i - 1;
    while(j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    rep(j,n) {
      if(j != n-1) {
        cout << a[j] << ' ';
      }else{
        cout << a[j] << endl;
      }
    }
  }
  return 0;
}

