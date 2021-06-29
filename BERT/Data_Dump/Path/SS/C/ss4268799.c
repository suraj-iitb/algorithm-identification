#include <bits/stdc++.h>
#define INF 10000000000
using namespace std;

struct edge {int to, cost;};

//=============dijkstra============================
vector<long long> dijkstra(int s, int V, vector<vector<edge>> G)
{
  vector<long long> d(V, INF);
  typedef pair<long long, int> P;// first は最短距離　second は頂点の番号
  priority_queue<P, vector<P>, greater<P>> que;
  d.at(s) = 0;
  que.push(P(0, s));
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d.at(v) < p.first) continue;
    for (int i = 0; i < G.at(v).size(); ++i)
    {
      edge e = G.at(v).at(i);
      if (d.at(e.to) > d.at(v) + e.cost)
      {
        // cout << d.at(v) + e.cost << " " << e.to << endl;
        d.at(e.to) = d.at(v) + e.cost;
        que.push(P(d.at(e.to), e.to));
      }
    }
  }
  return d;
}
//=================================================

int main()
{
  int V, E, r;
  cin >> V >> E >> r;
  vector<vector<edge>> G(V, vector<edge>(0));
  int s, t, d;
  for (int i = 0; i < E; ++i)
  {
    cin >> s >> t >> d;
    edge e = {t, d};
    G.at(s).push_back(e);
    // cout << e.to << e.cost << endl;
    // G.at(t).push_back({s, d});
  }
  vector<long long> ans = dijkstra(r, V, G);
  for (int i = 0; i < V; ++i)
  {
    if (ans.at(i) == INF)
    {
      cout << "INF" << endl;
    }
    else
    {
      cout << ans.at(i) << endl;
    }
  }
}

