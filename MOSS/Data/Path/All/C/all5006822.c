#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
#define RAP(i, n) for(ll i=0;i<(n);i++)
#define FOR(i, a, b) for(ll i=(a);i<(b);i++)

#include <iostream>
#include <vector>
const int IINF =  0x3f3f3f3f; // 2倍しても負にならない
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF; // #define int long long 対策
const double eps = 1e-15;
using namespace std;

//重複順列
vector<ll> buf;
void permutation(ll i, const ll size, const ll range_start, const ll range_end)
{
    if (i == size) {
      // ここで所望の作業を行う
      for(ll itr:buf){
        cout << itr;
      }
    }
    else{
        for(ll j = range_start; j <= range_end; ++j){
            buf[i] = j;
            permutation(i + 1, size, range_start, range_end);
        }
    }
}
// ダイクストラ法
struct edge{ll to, cost;};
typedef pair<ll,ll> P;
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;// 頂点sからの最短距離

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    RAP(i,V){
      d[i] = INF;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    RAP(i,V){
      d[i] = INF;
    }
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
};


int main(void)
{
  ll v, e, s, t;
  cin >> v >> e;
  vector<vector<ll>> G(v, vector<ll> (v, LINF));
  RAP(i, v){
    G[i][i] = 0;
  }
  RAP(i,e){
    cin >> s >> t;
    cin >> G[s][t];
  }
  RAP(k, v){
    RAP(i, v){
      RAP(j, v){
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }
  bool check = false;
  RAP(i, v){
    if(G[i][i]<0){
      check = true;
    }
  }
  if(check){
    cout << "NEGATIVE CYCLE" << endl;
  }else{
    RAP(i, v){
      RAP(j, v){
        if(G[i][j]>LINF/10){
          cout << "INF";
        }else{
          cout << G[i][j];
        }
        if(j!=v-1){
          cout << " ";
        }
      }

      cout << endl;
    }
  }
  return 0;
}

