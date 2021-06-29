#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define answer cout << ans << endl;
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;

class Edge {
public:
  int to;     // 辺の行き先
  int weight; // 辺の重み
  Edge(int t, int w) : to(t), weight(w) { }
};

using Graph = vector<vector<Edge>>;
typedef pair<int,int> P;// first は最短距離、 second は頂点の番号

signed _main() {
  // 頂点数と辺数
  int N, M, r; cin >> N >> M >> r;

  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b, d;
    cin >> a >> b >> d;
    G[a].push_back(Edge(b,d));
  }

  // BFS のためのデータ構造
  vector<int> dist(N, INF); // 全頂点を「未訪問」に初期化
  priority_queue<P,vector<P>,greater<P>> que;

  // 初期条件 (頂点 0 を初期ノードとする)
  dist[r] = 0;
  que.push(P(0,r)); // 0 を橙色頂点にする

  // BFS 開始 (キューが空になるまで探索を行う)
  while (!que.empty()) {
    P p = que.top(); // キューから先頭頂点を取り出す
    int v=p.second;
    que.pop();

    if(dist[v]<p.first) continue;//
    // v から辿れる頂点をすべて調べる
    for (auto &nv : G[v]) {
      if(dist[nv.to]>dist[v]+nv.weight){
        dist[nv.to]=dist[v]+nv.weight;
        que.push(P(dist[nv.to],nv.to));
      }
    }
  }

  // 結果出力 (各頂点の頂点 0 からの距離を見る)
  for (int v = 0; v < N; ++v){
    if(dist[v]>=INF/2) cout << "INF" << endl;
    else cout << dist[v] << endl;
  }
}

