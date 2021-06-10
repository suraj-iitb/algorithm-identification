#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

typedef long long ll;

#define INF 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}
// const long long INF = 10000000000000000; // 10e16	


/* params	
 * @s -> start, n -> 要素数, G -> グラフ, d -> 結果(参照渡し)	
 * グラフの要素を0 ~ n - 1として見る	
*/	

struct edge { long long to, cost;};	
typedef pair<long long, long long> P_dij;	
void dijkstra(const long long s, const long long n,	
  vector< vector<edge> > const &G, vector<long long> & d){	
  d.resize(n);	
  for(int i=0; i<n; i++) d[i] = INF; 	
  priority_queue<P_dij, vector<P_dij>, greater<P_dij>> que;	
  d[s] = 0;	
  que.push(P_dij(0, s));	
  while (!que.empty()) {	
    P_dij p = que.top();	
    que.pop();	
    long long v = p.second;	
    if(d[v] < p.first)continue;	
    for(int i=0;i<G[v].size(); i++){	
      edge e = G[v][i];	
      if(d[e.to] > d[v] + e.cost){	
        d[e.to] = d[v] + e.cost;	
        que.push(P_dij(d[e.to], e.to));	
      }	
    }	
  }	
}	

/* END END END */	

int main() {
  int v, e, r;
  cin >> v >> e >> r;
  vector<vector<edge>> g(v);
  vector<ll> d;
  for (int i = 0; i < e; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edge e1 = {b, c};
    // edge e2 = {a, c};
    g[a].push_back(e1);
    // g[b].push_back(e2);
  }

  dijkstra(r, v, g, d);
  // nfor (auto itr : d) cout << itr << endl;
  
  for (int i = 0; i < v; ++i) {
    if (d[i] == INF) cout << "INF" << endl;
    else cout << d[i] << endl;
  }
}

