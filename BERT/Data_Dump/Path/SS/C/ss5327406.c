#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
//constexpr ll MOD = 1e9 + 7;
constexpr ll MOD = 998244353;
//constexpr ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
constexpr ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
#define FINALANS(A) do {cout << (A) << '\n'; exit(0);} while (false)

class graph {
public:
  struct edge
  {
    ll to, cost;
    edge(ll to, ll cost) : to(to), cost(cost) {}

    bool operator<(const edge &right) const
    {
      return cost < right.cost;
    }

    bool operator>(const edge &right) const
    {
      return cost > right.cost;
    }
  };

  ll N;
  vector<vector<edge>> G;
  vector<ll> costs;

  graph(ll n)
  {
    N = n;
    G.resize(N);
  }

  void connect(ll sv, ll gv, ll c)
  {
    G.at(sv).push_back(edge(gv, c));
  }

  void connect2(ll v0, ll v1, ll c)
  {
    connect(v0, v1, c), connect(v1, v0, c);
  }

  void dijkstra(ll sv)
  {
    costs = vector<ll>(N, INF);
    costs.at(sv) = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    for (auto e : G.at(sv))
    {
      pque.push(make_pair(e.cost, e.to));
    }

    while (!pque.empty())
    {
      pll cv = pque.top();
      ll c = cv.first, v = cv.second;
      pque.pop();

      if (costs.at(v) != INF)
        continue;
      costs.at(v) = c;

      for (auto e : G.at(v))
      {
        if (costs.at(e.to) != INF)
          continue;

        pque.push(make_pair(c + e.cost, e.to));
      }
    }
  }
};

int main()
{
  ll V, E, r;
  cin >> V >> E >> r;

  graph g(V);
  for (ll i = 0; i < E; i++)
  {
    ll s, t, d;
    cin >> s >> t >> d;
    g.connect(s, t, d);
  }

  g.dijkstra(r);

  for (ll i = 0; i < V; i++)
  {
    ll ans = g.costs.at(i);
    
    if (ans == INF)
      cout << "INF" << endl;
    else
      cout << ans << endl;
  }
}
