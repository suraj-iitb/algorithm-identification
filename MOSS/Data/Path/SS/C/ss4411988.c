#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 100005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct edge{int to;ll cost;};
vector<edge> G[SIZE];
ll d[SIZE];

void dijkstra(int s){
  priority_queue<P,vector<P>,greater<P>> que;
  fill(d,d+SIZE,INF);
  d[s] = 0;
  que.push(P(0,s));

  while(!que.empty()){
    P p = que.top();que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(edge e : G[v]){
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to],e.to));
      }
    }
  }
}

void add_edge(int a,int b,ll c){
  G[a].push_back((edge){b,c});
}

int V,E,r;

int main(){
  cin >> V >> E >> r;
  rep(i,0,E){
    int s,t;
    ll D;
    cin >> s >> t >> D;
    add_edge(s,t,D);
  }
  dijkstra(r);
  rep(i,0,V){
    if(d[i] >= INF){
      cout << "INF" << endl;
      continue;
    }
    cout << d[i] << endl;
  }

  return 0;
}

