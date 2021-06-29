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

int ans = 0;

void merge(vector<int> &a, int left, int mid, int right) {
  int n1 = mid - left, n2 = right - mid;
  vector<int> l(n1 + 1), r(n2 + 1);
  REP(i, n1) l[i] = a[left + i];
  REP(i, n2) r[i] = a[mid + i];
  l[n1] = r[n2] = INF;
  int i = 0, j = 0;
  FOR(k, left, right) {
    if (l[i] <= r[j]) {
      a[k] = l[i];
      i = i + 1;
    } else {
      a[k] = r[j];
      j = j + 1;
    }
    ++ans;
  }
}

void mergeSort(vector<int> &a, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) >> 1;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  mergeSort(a, 0, n);
  REP(i, n) cout << a[i] << " \n"[i + 1 == n];
  cout << ans << '\n';
  return 0;
}

