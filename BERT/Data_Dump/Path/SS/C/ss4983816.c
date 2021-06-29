#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Edge {
   int to;
   ll w;
   Edge(int to, ll w) : to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;
const ll INF = 1LL << 60;
template<class T> bool chmin(T &a, T b) {
   if (a > b) {
      a = b;
      return true;
   } else {
      return false;
   }
}

void Dijkstra(Graph &G, vector<ll> &dist, int s) {
   int N = G.size();
   dist[s] = 0;
   priority_queue<
      pair<ll, int>,
      vector<pair<ll, int>>,
      greater<pair<ll, int>>
      > que;
   que.push(make_pair(dist[s], s));

   while (!que.empty()) {
      int v = que.top().second;
      ll d = que.top().first;
      que.pop();
      if (d > dist[v]) continue;

      for (auto e : G[v]) {
         if (chmin(dist[e.to], dist[v] + e.w)) {
            que.push(make_pair(dist[e.to], e.to));
         }
      }
   }
}

int main() {
   int N, E, r; cin >> N >> E >> r;
   Graph G(N);
   for (int i=0; i<E; i++) {
      int s, t; ll d; cin >> s >> t >> d;
      G[s].push_back(Edge({t, d}));
   }
   vector<ll> dist(N, INF);
   Dijkstra(G, dist, r);
   for (int i=0; i<N; i++) {
      if (dist[i] == INF) {
         cout << "INF" << endl;
      } else {
         cout << dist[i] << endl;
      }
   }
}

