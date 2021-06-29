#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;
struct poi{int to,cost;
  poi(int t, int c){
    to = t;cost = c;
  }
  };
vector<ll> d;
vector<vector<poi> > edges;
int V,E,r;
ll INF = 5000000000;

/*bool berm(){
  for(int ct=0;ct<V;ct++){
    for(int i=0;i<E;i++){
      int v = edges[i].to;
      int u = edges[i].from;
      int c = edges[i].cost;
      if(d[u] + c < d[v]){
	d[v] = d[u] + c;
		if(ct == V-1){
	  return false;
	  }
      }
    }
  }
  return true;
  }*/
typedef pair<int,int> P;
int dijk(){
  priority_queue<P,vector<P>,greater<P> > que;
  que.push(P(0,r));
  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0;i < edges[v].size(); i++){
      poi e = edges[v][i];
      if (d[e.to] > d[v] + e.cost){
	d[e.to] = d[v] + e.cost;
	que.push(P(d[e.to], e.to));
      }
    }
  }
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> V >> E >> r;//V is number of point,E is number of hen,r is defpoint
  d.resize(V,INF);
  d[r] = 0;
  edges.resize(V,vector<poi>());
  REP(i,E){
    int from,to,cost;
    cin >> from >> to >> cost;
    edges[from].push_back(poi(to,cost));
  }
  dijk();
  REP(i,V)
    if(d[i] == INF)cout << "INF" << endl;
    else cout << d[i] << endl;
  return 0;
}
