#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) begin(v), end(v)
#define allg(v) begin(v), end(v), greater<int>()

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  rep(i, 0, n) cin >> a.at(i);
  
  int cnt = 0;
  bool flag = 1;
  while (flag) {
    flag = 0;
    for(int j = n-1; j >= 1; j--) {
      if (a.at(j) < a.at(j-1)) {
        swap(a.at(j), a.at(j-1));
        cnt++;
        flag = 1;
      }
    }
  }
  
  rep(i, 0, n-1)
    cout << a.at(i) << " ";
  cout << a.at(n-1) << "\n";
  cout << cnt << "\n";

}

