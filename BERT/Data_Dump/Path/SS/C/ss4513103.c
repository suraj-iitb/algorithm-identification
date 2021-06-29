#include <bits/stdc++.h>
#define REP(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define whole(x) (x).begin(), (x).end()
#define fr first
#define sc second
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
constexpr int INF = 1<<30;
constexpr long long LINF = 1LL<<60;
template<class T, class U> inline bool chmax(T &a, const U &b) { if(a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if(a > b) { a = b; return true; } return false; }

int V, E, r;
vector<P> g[100000];

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  cin >> V >> E >> r;
  rep(i, E) {
    int s, t, d;
    cin >> s >> t >> d;
    g[s].emplace_back(t, d);
  }
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.emplace(0, r);
  vector<ll> d(V, LINF);
  d[r] = 0;
  while(!pq.empty()) {
    P p = pq.top();
    pq.pop();
    if(p.fr > d[p.sc]) continue;
    for(auto e : g[p.sc]) {
      if(chmin(d[e.fr], p.fr+e.sc)) {
        pq.emplace(d[e.fr], e.fr);
      }
    }
  }
  rep(i, V) {
    if(d[i] == LINF) cout << "INF" << '\n';
    else cout << d[i] << '\n';
  }
  return 0;
}
