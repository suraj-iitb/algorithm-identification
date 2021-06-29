#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 1<<30

typedef long long ll;

struct edge{
  ll to;
  ll cost;
};

typedef pair<ll,ll> P;

const ll MAX_V = 100000, MAX_E = 500000;

ll V, E, r;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(ll s){
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d+V, INF);
  d[s] = 0;
  que.push(P(0,s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    ll v = p.second;
    if (d[v] < p.first) continue;

    for (ll i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to]>d[v]+e.cost) {
        d[e.to] = d[v]+e.cost;
        que.push(P(d[e.to],e.to));
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  cin >> V >> E >> r;
  for (ll i = 0; i < E; i++) {
    ll s, t, dist;
    cin >> s >> t >> dist;
    edge e = {t, dist};
    G[s].push_back(e);
  }
  dijkstra(r);
  for (ll i = 0; i < V; i++)
  {
    if (d[i]==INF) cout << "INF" << endl;
    else cout << d[i] << endl;
  }
  return 0;
}

