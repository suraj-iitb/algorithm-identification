#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m);i>=(int)(n);--i)
#define debug(x) cout << #x << "=" << (x) << endl;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> void fail(T v){cout << v << endl;exit(0);}
//template end
template< typename T >
struct Dijkstra{
  private:
  vector<vector<pair<T,int>>> edge;
  public:
  Dijkstra(int sz){
    edge.assign(sz,vector<pair<T,int>>(0));
  }
  void addEdge(int from,int to,T cost){
    edge[from].push_back(make_pair(cost,to));
  }
  vector<T> Execute(int st){
    const auto INF=numeric_limits< T >::max();
    vector<T> dist(edge.size(),INF);
    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> pq;
    dist[st]=0;
    pq.emplace(0,st);
    while(!pq.empty()){
      T cost;int idx;
      tie(cost,idx)=pq.top();pq.pop();
      if(cost>dist[idx])continue;
      for(auto &e :edge[idx])
        if(chmin(dist[e.second],e.first+cost))
          pq.emplace(dist[e.second],e.second);
    }
    return dist;
  }
};
void solve(){
  int V,E,r;
  cin>>V>>E>>r;
  Dijkstra<int> dij(V);
  rep(i,E){
    int s,t,d;
    cin>>s>>t>>d;
    dij.addEdge(s,t,d);
  }
  auto dist=dij.Execute(r);
  rep(i,V)
    if(dist[i]==INT_MAX)
      cout<<"INF"<<endl;
    else cout<<dist[i]<<endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

