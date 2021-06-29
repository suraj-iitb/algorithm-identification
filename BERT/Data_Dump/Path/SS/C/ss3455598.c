///////////////////////////////////
// dijkstra
///////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

using ll = long long;
using ld = long double;

//
// graph template
//
template<typename T>
struct edge{
  int from;
  int to;
  T cost;
  edge(){}
  edge(int from, int to, T cost): from(from), to(to), cost(cost) {}
  edge(int to, T cost): to(to), cost(cost) {}
};

template<typename T>
using graph = vector< vector< edge< T > > >;

template<typename T>
class Graph{
protected:
  int n;
  graph<T> g;

public:
  Graph(int sz): n(sz) { init(n); }
  
  void init(int num){
    n = num;
    g = graph<T>(num);
  }
  
  int size(){ return n; }

  void resize(int num){
    n = num;
    g.resize(num);
  }

  void addEdge(int u, int v, T w){
    g[u].push_back( edge<T>(u, v, w) );
    g[v].push_back( edge<T>(v, u, w) );
  }

  void addUniEdge(int from, int to, T w){
    g[from].push_back( edge<T>(from, to, w) );
  }
};


//
// dijkstra (class)
//
template<typename T>
class Dijkstra : public Graph<T>{
private:
  using Graph<T>::n;
  using Graph<T>::g;
  T inf,zero;
  vector<T> dist;
  vector<int> par;

public:
  Dijkstra(int sz, T zeroa, T infa) : Graph<T>(sz){
    inf = infa;
    zero = zeroa;
    dist = vector<T>(n, inf);
    par = vector<int>(n, -1);
  }

  void calcDist(int start){
    priority_queue<edge<T>, vector<edge<T>>, function<bool(edge<T>, edge<T>)>>
      heap([](const edge<T> &a, const edge<T> &b){return a.cost > b.cost;});
    heap.push( edge<T>(-1, start, zero) );
    while( !heap.empty() ){
      edge<T> now = heap.top();
      heap.pop();
      if(dist[now.to] != inf) continue;
      dist[now.to] = now.cost;
      par[now.to] = now.from;
      for(auto &e : g[now.to]){
        if(dist[e.to] == inf){
          heap.push( edge<T>(now.to, e.to, now.cost+e.cost) );
        }
      }
    }
  }

  T getDist(int goal){
    return dist[goal];
  }

  vector<int> getShortestPath(int goal){
    int now = goal;
    vector<int> ans;
    while(now != -1){
      ans.push_back(now);
      now = par[now];
    }
    reverse(all(ans));
    return ans;
  }
};


//
// dijkstra (inline)
//
int main(){

  int n,m,r;
  cin >> n >> m >> r;
  int start=r;
  graph<ll> g(n);
  int s,t,d;
  for(int i=0;i<m;i++){
    cin >> s >> t >> d;
    g[s].push_back(edge<ll>(s,t,d));
  }
  vector<ll> dist(n, LINF);
  vector<int> par(n, -1);
  priority_queue<edge<ll>, vector<edge<ll>>, function<bool(edge<ll>, edge<ll>)>>
    heap([](const edge<ll> &a, const edge<ll> &b){return a.cost > b.cost;});
  heap.push( edge<ll>(-1, start, 0) );
  while( !heap.empty() ){
    edge<ll> now = heap.top();
    heap.pop();
    if(dist[now.to] != LINF) continue;
    dist[now.to] = now.cost;
    par[now.to] = now.from;
    for(auto &e:g[now.to]){
      int next=e.to;
      if(dist[next] == LINF){
        ll newcost=e.cost;
        heap.push( edge<ll>(now.to, next, now.cost+newcost) );
      }
    }
  }
  for(int i=0;i<n;i++){
    if(dist[i]==LINF){
      cout << "INF" << endl;
    }else{
      cout << dist[i] << endl;
    }
  }

  // int goal;
  // int now = goal;
  // vector<int> sp; // shortest path of start->goal
  // while(now != -1){
  //   sp.push_back(now);
  //   now = par[now];
  // }
  // reverse(all(sp));

  // int n,m,r;
  // cin >> n >> m >> r;
  // Dijkstra<int> dijk(n,0,IINF);
  // int s,t,d;
  // for(int i=0;i<m;i++){
  //   cin >> s >> t >> d;
  //   dijk.addUniEdge(s,t,d);
  // }
  // dijk.calcDist(r);
  // for(int i=0;i<n;i++){
  //   int dist=dijk.getDist(i);
  //   if(dist==IINF){
  //     cout << "INF" << endl;
  //   }else{
  //     cout << dist << endl;
  //   }
  // }
  return 0;
}
