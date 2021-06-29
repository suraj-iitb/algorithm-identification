#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int bubbleSort(vector<int> &a, int n) {
  int res = 0;
  bool flag = true;
  while (flag) {
    flag = false;
    for (int j = n - 1; j >= 1; --j) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        flag = true;
        ++res;
      }
    }
  }
  return res;
}

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  int ans = bubbleSort(a, n);
  REP(i, n) cout << a[i] << " \n"[i + 1 == n];
  cout << ans << '\n';
}

