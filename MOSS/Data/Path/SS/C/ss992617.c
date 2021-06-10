#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin(); it!=(c).end(); it++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pr(a) cout << (a) << endl
typedef long long ll;
typedef pair<int,int> P;
const int MAX=1000000000;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
struct edge{int to,cost;};

int main() {
  int n,m,s;
  cin >> n >> m >> s;
  vector<edge> G[n];
  rep(i,m) {
    edge e;
    int x;
    cin >> x >> e.to >> e.cost;
    G[x].pb(e);
  }
  int d[n];
  fill(d,d+n,MAX);
  d[s]=0;
  priority_queue<P,vector<P>,greater<P> > que;
  que.push(P(0,s));
  while(!que.empty()) {
    P p=que.top();
    que.pop();
    int v=p.second;
    if(d[v]<p.first) continue;
    for(int i=0; i<G[v].size(); i++) {
      edge e=G[v][i];
      if(d[e.to]>d[v]+e.cost) {
	d[e.to]=d[v]+e.cost;
	que.push(P(d[e.to],e.to));
      }
    }
  }
  rep(i,n) {
    if(d[i]==MAX) pr("INF");
    else pr(d[i]);
  }
  return 0;
}
