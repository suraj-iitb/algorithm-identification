#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const long long INF = 1LL << 60;
const int Inf  = 10000*100000+100;
const int MOD = 1000000007;

int main() {
   int V, E, r; cin >> V >> E >> r;
   vector<vector<pair<int,int> > > Graph(V); // 隣接リスト
   for (int i = 0; i < E; ++i) {
       int s, t, d; cin >> s >> t >> d;
       Graph[s].push_back({t, d});
   }
   vector<int> dist(V, Inf); // 距離を管理　Infで初期化
   dist[r] = 0;

   for (int t = 0; t < V; ++t) {
       bool update = false;
       for (int i = 0; i < V; ++i) {
           for (auto e : Graph[i]) {
               if (dist[e.first] > dist[i] + e.second) {
                   dist[e.first] = dist[i] + e.second;
                   update = true;
               }
           }
       }
       if (!update) break;
   }

   for (int i = 0; i < V; ++i) {
       if (dist[i] < Inf) cout << dist[i] << endl;
       else cout << "INF" << endl;
   }
}

