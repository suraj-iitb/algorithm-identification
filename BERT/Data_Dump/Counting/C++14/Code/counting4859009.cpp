#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
// using P = pair<ll, ll>;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

#define MAX 2000000
vector<int> a, b, c;
int n;

void CountingSort() {
  rep(i, MAX) c[i] = 0;
  rep(i, n) c[a[i]]++;
  repi(i, 1, MAX) c[i] += c[i - 1];
  for (int j = n - 1; j >= 0; --j) {
    b[c[a[j]] - 1] = a[j];
    c[a[j]]--;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////
  cin >> n;
  a.resize(n);
  b.resize(n);
  c.resize(MAX);
  rep(i, n) cin >> a[i];
  CountingSort();
  rep(i, n) {
    if (i) cout << " ";
    cout << b[i];
  }
  cout << endl;
  return 0;
}

