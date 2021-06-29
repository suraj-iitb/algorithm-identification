#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 9999999999;
vector<int> x4 = {0, 1, 0, -1};
vector<int> y4 = {1, 0, -1, 0};
vector<int> x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
  T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }

struct edge {
  int to, cost;
  edge(int to, int cost) : to(to), cost(cost) {}
};
typedef pair<int, int> P; // firstは最短距離、secondは頂点の番号

int N; // 頂点数
const int MAX_N = 100000;
const int INFC = 1000000000;
vector<vector<edge>> G(MAX_N);
vector<int> d(MAX_N); // 頂点sからの最短距離

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P> > que; // 小さい順に取り出す
  rep(i, N) d[i] = INFC;
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i=0; i<G[v].size(); i++){
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main() {
  cin >>N;
  int M; cin >>M;
  int s; cin >>s;
  rep(i, M){
    int a,b,c; cin >>a >>b >>c;
    G[a].push_back(edge(b, c));
  }
  dijkstra(s);
  rep(i, N){
    if (d[i] == INFC) cout <<"INF";
    else cout <<d[i];
    cout <<endl;
  }
}
