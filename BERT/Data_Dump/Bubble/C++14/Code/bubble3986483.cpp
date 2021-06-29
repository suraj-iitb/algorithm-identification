#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;

int main() {
  int n,count = 0;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  bool flag = true;
  while(flag) {
    flag = false;
    for(int i = n-1; i > 0; i--) {
      if(a[i] < a[i-1]) {
        swap(a[i],a[i-1]);
        count++;
        flag = true;
      }
    }
  }
  
  rep(i,n) {
    if(i != n-1) cout << a[i] << ' ';
    else cout << a[i] << endl;
  }
  cout << count << endl;
  return 0;
}
