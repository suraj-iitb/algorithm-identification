#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) begin(v), end(v)
#define allg(v) begin(v), end(v), greater<int>()

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> is(n);
  rep(i, 0, n)
    cin >> is.at(i);
  rep(k, 0, n-1)
    cout << is.at(k) << " ";
  cout << is.at(n-1) << "\n";
  
  rep(i, 1, n) {
    int v = is.at(i);
    int j = i-1;
    while (j >= 0 and is.at(j) > v) {
      is.at(j+1) = is.at(j);
      j--;
    }
    is.at(j+1) = v;
    
    rep(k, 0, n-1)
      cout << is.at(k) << " ";
    cout << is.at(n-1) << "\n";
  }

}
