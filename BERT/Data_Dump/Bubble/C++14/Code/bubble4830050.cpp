#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int ans = 0;

void insertationSort(vector<int>& a, int n) {
  repi(i, 1, n) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    rep(i, n - 1) cout << a[i] << " ";
    cout << a[n - 1] << endl;
  }
}

void bubbleSort(vector<int>& a, int n) {
  int flag = 1;
  while (flag) {
    flag = 0;
    for (int i = n - 1; i > 0; i--) {
      if (a[i] < a[i - 1]) {
        swap(a[i], a[i - 1]);
        ans++;
        flag = 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  bubbleSort(a, n);
  rep(i, n - 1) cout << a[i] << " ";
  cout << a[n - 1] << endl;
  cout << ans << endl;
  return 0;
}

