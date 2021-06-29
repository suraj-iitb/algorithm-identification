#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) {a = b; return true;} else return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) {a = b; return true;} else return false;}

const ll INF = 1LL << 60;

struct Edge {
  int to;
  ll w;
  // メンバ初期化リスト 変数（初期値）
  Edge(int to, ll w) : to(to), w(w) {};
};
using Graph = vector<vector<Edge>>;

int main () {
  // 頂点数、辺数、始点
  int N, M, s;
  cin >> N >> M >> s;
  //グラフ
  Graph G(N);
  rep(i, M) {
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back(Edge(b, w));
  }
  // ダイクストラ法
  vector<ll> dist(N, INF);
  // 始点の距離を0とする
  dist[s] = 0;
  // (d[v], v)のペアを要素としたヒープを作る
  priority_queue< pair<ll, int>, 
                  vector<pair<ll, int>>,
                  greater<pair<ll, int>> > que;
  que.push(make_pair(dist[s], s));
  while (!que.empty()) {
    // v：「使用済み」でない頂点のうちdist値が最小のもの
    int v = que.top().second;
    ll d = que.top().first;
    que.pop();

    // d > dist[v] はゴミデータ
    if (d > dist[v]) continue;

    // 頂点vを始点とした各辺を緩和
    for (auto e : G[v]) {
      if (chmin(dist[e.to], dist[v]+e.w)) {
        que.push(make_pair(dist[e.to], e.to));
      }
    }
  }

  // 結果出力
  for (int v = 0; v < N; ++v) {
    if (dist[v] != INF) cout << dist[v] << endl;
    else cout << "INF" << endl;
  }
}
