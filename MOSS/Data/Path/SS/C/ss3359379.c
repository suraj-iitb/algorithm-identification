#include <bits/stdc++.h>
using namespace std;
const int infty = 1e9;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, r;
  cin >> n >> m >> r;
  vector<vector<pair<int, int> > > grh(n);
  for (int i = 0; i < m; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    grh[s].push_back({d, t});
  }
  vector<int> dst(n);
  for (int i = 0; i < n; i++) {
    dst[i] = infty;
  }
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > prque;
  prque.push({0, r});
  dst[r] = 0;
  while (!prque.empty()) {
    pair<int, int> crr = prque.top();
    prque.pop();
    int crrd = crr.first;
    int crrv = crr.second;
    if (crrd > dst[crrv]) {
      continue;
    }
    for (int k = 0; k < grh[crrv].size(); k++) {
      pair<int, int> nxt = grh[crrv][k];
      int nxtd = crrd + nxt.first;
      int nxtv = nxt.second;
      if (nxtd > dst[nxtv]) {
        continue;
      }
      prque.push({nxtd, nxtv});
      dst[nxtv] = nxtd;
    }
  }
  for (int i = 0; i < n; i++) {
    if (dst[i] == infty) {
      cout << "INF" << '\n';
    } else {
      cout << dst[i] << '\n';
    }
  }
  return 0;
}
