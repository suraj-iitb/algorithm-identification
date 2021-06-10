#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

const int MOD_TYPE = 1;
const ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
const int INF = (int)1e9;
const ll LINF = (ll)4e18;
const double PI = acos(-1.0);

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define possible(n) cout << ((n) ? "possible" : "impossible") << endl
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << endl
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << endl;

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

const ll MAX_V = 200010;

class dijkstra
{
public:
  struct edge
  {
    ll to;
    ll cost;
  };

  vector<edge> E[MAX_V];
  ll d[MAX_V];

  void calc(ll s)
  {
    priority_queue<pll, vector<pll>, greater<pll>> que;
    rep(i, MAX_V) d[i] = LINF;
    que.emplace(0LL, s);
    d[s] = 0LL;
    while (!que.empty())
    {
      pll p = que.top();
      que.pop();
      ll v = p.second;
      if (d[v] < p.first)
        continue;

      for (auto &&e : E[v])
      {
        if (d[e.to] > d[v] + e.cost)
        {
          d[e.to] = d[v] + e.cost;
          que.emplace(d[e.to], e.to);
        }
      }
    }
  }
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll v, e, r;
  cin >> v >> e >> r;
  dijkstra ds;
  rep(i, e)
  {
    ll s, t, d;
    cin >> s >> t >> d;
    ds.E[s].push_back({t, d});
  }
  ds.calc(r);
  rep(i, v)
  {
    if (ds.d[i] == LINF)
      cout << "INF\n";
    else
      cout << ds.d[i] << endl;
  }
  return 0;
}

