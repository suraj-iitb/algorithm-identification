#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
#define P pair<int, int>
#define ll long long
using namespace std;

struct edge {int to, cost; };

const int MAX_V=100000;
const int INF=1000000001;

int V,E;
vector<edge> G[MAX_V+1];
int d[MAX_V+1];

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d+V, INF);
  d[s]=0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p=que.top(); que.pop();
    int v=p.second;
    if (d[v]<p.first) continue;
    for (int i=0; i<G[v].size(); i++) {
      edge e=G[v][i];
      if (d[e.to]>d[v]+e.cost) {
        d[e.to]=d[v]+e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main() {
  cin>>V>>E;
  int s; cin>>s;
  rep(i, E) {
    int a,b,c; cin>>a>>b>>c;
    G[a].push_back(edge{b, c});
  }
  dijkstra(s);
  rep(i, V) {
    if (d[i]==INF) cout<<"INF"<<endl;
    else cout<<d[i]<<endl;
  }
}

