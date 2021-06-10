#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T> struct Dijkstra{
  struct edge{
    int to;
    T cost;
    edge(){}
    edge(int to,T cost):to(to),cost(cost){}
    bool operator<(const edge& o) const{ return cost > o.cost; }
  };

  T inf() { return numeric_limits<T>::max(); }

  vector<vector<edge>> G;
  vector<T> ds;
  vector<int> bs;

  Dijkstra(int n):G(n),ds(n,inf()),bs(n,-1){}

  void add_edge(int from,int to,T cost){ G[from].emplace_back(to,cost); }

  void build(int s) {
    int n = G.size();
    ds.assign(n, inf());
    bs.assign(n, -1);

    priority_queue<edge> pq;
    ds[s] = 0;
    pq.emplace(s, ds[s]);

    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int v = p.to;
      if (ds[v] < p.cost)
        continue;
      for (auto e : G[v]) {
        if (ds[e.to] > ds[v] + e.cost) {
          ds[e.to] = ds[v] + e.cost;
          bs[e.to] = v;
          pq.emplace(e.to, ds[e.to]);
        }
      }
    }
  }

  T operator[](int k){ return ds[k]; }

  vector<int> restore(int to){
    vector<int> res;
    if(bs[to]==-1) return res;
    
    while(to!=-1){
      res.emplace_back(bs[to]);
      to=bs[to];
    }
    reverse(res.begin(),res.end());
    return res;
  }
};

int main(){
  int V,E,r;
  cin>>V>>E>>r;

  Dijkstra<ll> G(V);

  for(int i=0;i<E;i++){
    int s,t;
    ll d;
    cin>>s>>t>>d;
    G.add_edge(s,t,d);
  }

  G.build(r);
  for(int i=0;i<V;i++){
    if(G[i]==G.inf()){
      cout<<"INF\n";
      continue;
    }
    cout<<G[i]<<'\n';
  }
}
