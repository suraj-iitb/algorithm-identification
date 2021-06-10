#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define each(x, y) for (auto &x : y)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ll << (b))
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define rsort(v) sort(all(v)); reverse(all(v))

using namespace std;

using i32 = int;
using i64 = long long;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

inline void yes() { cout << "Yes" << '\n'; exit(0); }
inline void no() { cout << "No" << '\n'; exit(0); }
inline i64 gcd(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); if (a % b == 0) return b; return gcd(b, a % b); }
inline i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }
template<typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template<typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template<typename T> inline void amax(T &x, T y) { if (x < y) x = y; }
template<typename T> inline void amin(T &x, T y) { if (x > y) x = y; }
template<typename T> inline T power(T x, i64 n) { T r = 1; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }

template <typename T>
struct Matrix {
  vector<vector<T>> v;
  int r, c;
  Matrix(int r, int c, T d) : r(r), c(c) {
    v = vector<vector<T>>(r, vector<T>(c, d));
  }
  vector<T>& operator[](int x) {
    return v[x];
  }
};

template <typename T>
void warshall_floyd(Matrix<T> &m, T INF) {
  int n = m.r;
  rep(k, n) rep(i, n) rep(j, n) {
    if (m[i][k] == INF || m[k][j] == INF) continue;
    amin(m[i][j], m[i][k] + m[k][j]);
  }
}

void solve() {
  int V, E; cin >> V >> E;
  auto m = Matrix<i64>(V, V, 1e18);
  rep(i, V) m[i][i] = 0;
  rep(i, E) {
    int s, t, d; cin >> s >> t >> d;
    m[s][t] = d;
  }
  warshall_floyd(m, (i64) 1e18);
  rep(i, V) if (m[i][i] < 0) {
    cout << "NEGATIVE CYCLE" << '\n';
    return;
  }
  rep(i, V) {
    rep(j, V) {
      if (j) cout << " ";
      if (m[i][j] == 1e18) cout << "INF";
      else cout << m[i][j];
    }
    cout << '\n';
  }
}

