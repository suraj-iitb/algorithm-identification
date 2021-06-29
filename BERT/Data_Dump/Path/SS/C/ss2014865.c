#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int INF = 1000000000;

struct edge{int to,cost;};

typedef pair<int,int> P;

vector<edge> G[100000];
priority_queue<P,vector<P>,greater<P> > q;

int V,E,r;
int d[100000];

int main(){
  scanf("%d %d %d",&V,&E,&r);
  for(int i=0;i<E;i++){
    int s;
    edge e;
    scanf("%d %d %d",&s,&e.to,&e.cost);
    G[s].push_back(e);
  }
  fill(d,d+V,INF);
  d[r] = 0;
  q.push(P(0,r));
  while(!q.empty()){
    P p = q.top();
    q.pop();
    if(d[p.second]<p.first) continue;
    int v = p.second;
    for(int i=0;i<G[v].size();i++){
      if(d[G[v][i].to]>d[v]+G[v][i].cost){
        d[G[v][i].to] = p.first+G[v][i].cost;
        q.push(P(d[G[v][i].to],G[v][i].to));
      }
    }
  }
  for(int i=0;i<V;i++){
    if(d[i]==INF) printf("INF\n");
    else printf("%d\n",d[i]);
  }
  return 0;
}
