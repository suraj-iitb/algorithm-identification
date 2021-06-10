#include <bits/stdc++.h>
using namespace std;
//using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define SIZE 100005
#define inf 2e9

struct Edge{
  Edge(int to_, int dist_) {
    to=to_;
    dist=dist_;
  }
  int to,dist;
};
struct info{
  info(int node_, int dist_) {
    node=node_;
    dist=dist_;
  }
  bool operator<(const struct info &arg) const {
    return dist>arg.dist;
  }
  int node,dist;
};

int v,e,start;
vector<Edge> G[SIZE];
int min_dist[SIZE];

int main(void) {
  cin >> v >> e >> start;
  int s,t,d;
  rep(i,e) {
    cin >> s >> t >> d;
    G[s].push_back(Edge(t,d));
  }
  rep(i,v) min_dist[i]=inf;
  min_dist[start]=0;
  priority_queue<info> Q;
  Q.push(info(start,0));
  while(!Q.empty()) {
    if(Q.top().dist>min_dist[Q.top().node]) Q.pop();
    else {
      rep(i,G[Q.top().node].size()) {
        int next=G[Q.top().node][i].to;
        int next_dist=Q.top().dist+G[Q.top().node][i].dist;
        if(next_dist<min_dist[next]) {
          min_dist[next]=next_dist;
          Q.push(info(next,next_dist));
        }
      }
      Q.pop();
    }
  }
  rep(i,v) if(min_dist[i]==inf) printf("INF\n");
  else printf("%d\n",min_dist[i]);
}
