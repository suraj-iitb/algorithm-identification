#include <bits/stdc++.h>
using namespace std;

int n, num = 0;
vector<int> a, cnt, ans, anscnt;

void solve();

int main() {
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  solve();
  for(int i = 0; i < ans.size(); ++i) {
    if(i != 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}

void solve() {
  for(int i = 0; i < n; ++i) num = max(num, a[i]);
  cnt.assign(num + 1, 0);
  for(int i = 0; i < n; ++i) ++cnt[a[i]];
  for(int i = 0; i < num + 1; ++i)
    if(cnt[i] != 0) {
      for(int j = 0; j < cnt[i]; ++j) ans.push_back(i);
      anscnt.push_back(cnt[i]);
    }
}
