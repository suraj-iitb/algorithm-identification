#include<bits/stdc++.h>
using namespace std;
#define int int64_t
#define itn int
#define fi first
#define se second
typedef pair< int, int > Pi;
struct edge
{
  int to, cost;
};
typedef vector< vector< edge > > Graph;
const int INF = 1 << 30;
Graph g(100001,vector<edge>(0));
vector< int > min_cost(g.size(), INF);

int Dijkstra(Graph& graph, int s, int g)
{  
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  que.push(make_pair(0, s));
  min_cost[s] = 0;
  while(!que.empty()) {
    int now = que.top().second;
    int cost = que.top().first;
    que.pop();
    if(now == g) return(cost);
    if(cost > min_cost[now]) continue;
    for(int i = 0; i < graph[now].size(); i++) {
      edge& e = graph[now][i];
      if(cost + e.cost < min_cost[e.to]) {
        min_cost[e.to] = cost + e.cost;
        que.push(make_pair(min_cost[e.to], e.to));
      }
    }
  }
  return(-1);
}
signed main(){
    int v,e,r;
    int s,t,d;
    
    cin>>v>>e>>r;
    for(int i=0;i<e;i++){
        edge a;
        cin>>s>>t>>d;
        a.to=t;
        a.cost=d;
        g[s].push_back(a);
    }
    Dijkstra(g,r,v);
    for(int i=0;i<v;i++){
      if(min_cost[i]==INF) cout<<"INF\n";
      else cout<<min_cost[i]<<"\n";
        /*int q=Dijkstra(g,r,i);
        if(q==-1) cout<<"INF\n";
        else cout<<q<<"\n";
    */}
    return 0;
}
