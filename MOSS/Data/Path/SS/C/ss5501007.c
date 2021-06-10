#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < N; i++)
const int INF = 1000100100;
int main()
{
  int V, E, r;
  cin >> V >> E >> r;
  int s[E], t[E], d[E];
  rep(i, E) cin >> s[i] >> t[i] >> d[i];
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  // vector<vector<pair<int, int> > > G(V, vector<pair<int, int> >());

    vector<vector<pair<int, int> > > G(V, vector<pair<int, int> >());

  rep(i, E)
  {
    G[s[i]].push_back({d[i], t[i]});
  }
  int dist[100000];
  rep(i, V) dist[i] = INF;
  dist[r] = 0;
  pq.push(make_pair(0, r));
  while (!pq.empty())
  {
    int v = pq.top().second;
    int dis = pq.top().first;
    pq.pop();

    for(int i=0;i<G[v].size();i++) {
      pair<int, int> a = G[v][i];

 //   for (pair<int, int> a : G[v])
//    for(int ii=0; ii<(int)G[v].size();ii++)
 //   {
   //   pair<int, int> a = G[v][ii];
//      if (dist[a.second] > dist[v] + a.first)
            if (dist[a.second] > dist[v] + a.first)
      {
        dist[a.second] = dist[v] + a.first;
        pq.push(make_pair(dist[a.second], a.second));
      }
    }
  }
  for (int i = 0; i < V; i++)
  {
    if (dist[i] == INF)
      cout << "INF" << endl;
    else
      cout << dist[i] << endl;
  }
}

