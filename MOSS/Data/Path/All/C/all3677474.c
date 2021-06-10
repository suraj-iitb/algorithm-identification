#include <bits/stdc++.h>
using namespace std;
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
  const char* dlm = "";
  for(const auto& x:v) os << exchange(dlm, "\n") << x;
  return os;
}
struct Graph{
  using seen_t=int64_t; using ver_t=int32_t; using edge_t=pair<seen_t,ver_t>;
  const seen_t NO=1e18; vector<seen_t> seen;
  const ver_t NONE=-1; vector<ver_t> prev;
  vector<vector<edge_t>> edge;
  Graph(size_t n): seen(n,NO*2), prev(n,NONE), edge(n) {}

  void dijkstra(ver_t frm){
    seen[frm]=0;
    priority_queue<edge_t,vector<edge_t>,greater<edge_t>> que; que.push(make_pair(0,frm));
    ver_t u; seen_t alt;
    while(!que.empty()){
      u=que.top().second; que.pop();
      for(const auto& v:edge[u]){
        alt=seen[u]+v.first;
        if(seen[v.second]>alt){
          seen[v.second]=alt; prev[v.second]=u;
          que.push(make_pair(alt,v.second));
        }
      }
    }
  }
  // has negative => false
  bool bellmanford(ver_t frm){
    seen[frm]=0;
    seen_t alt;
    for(ver_t i=0; i<edge.size(); ++i){
      for(ver_t u=0; u<edge.size(); ++u){
        for(const auto& v:edge[u]){
          alt=seen[u]+v.first;
          if(seen[v.second]>alt){
            seen[v.second]=alt; prev[v.second]=u;
            if(i==edge.size()-1) return false;
          }
        }
      }
    }
    return true;
  }
  auto trace(ver_t frm, ver_t to){
    deque<ver_t> path(1,to);
    while(path[0]!=frm){
      path.push_front(prev[path[0]]);
    }
    return path;
  }
};
ostream& operator<<(ostream& os, const Graph& g){
  const auto* dlm="";
  for(const auto& x:g.seen){
    os<<exchange(dlm," ")<<(x>g.NO?"INF"s:to_string(x));
  }
  return os;
}
auto to_str(const Graph& g){
  string ret;
  const auto* dlm="";
  for(const auto& x:g.seen){
    (ret+=exchange(dlm," "))+=(x>g.NO?"INF"s:to_string(x));
  }
  return ret;
}
int32_t main(){
  ios::sync_with_stdio(false); cin.tie(0);
  // size_t n,m,r; cin>>n>>m>>r;
  size_t n,m; cin>>n>>m;
  Graph graph(n);
  int32_t s,t,d;
  for(size_t i=0; i<m; ++i){
    cin>>s>>t>>d;
    graph.edge[s].push_back(make_pair(d,t));
  }
  vector<string> ret(n);
  for(size_t i=0; i<n; ++i){
    fill(begin(graph.seen),end(graph.seen),graph.NO*2);
    if(!graph.bellmanford(i)){
      cout<<"NEGATIVE CYCLE\n"; return 0;
    }
    else ret[i]=to_str(graph);
  }
  cout<<ret<<endl;
}
