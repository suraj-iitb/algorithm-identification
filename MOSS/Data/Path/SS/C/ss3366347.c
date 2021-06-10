#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct edge {int to, cost;};
typedef pair<int,int> P;
const int MAX_V=100000,INF=1000000000;
int V,E,d[MAX_V],r,s,t,c,i;
vector<edge> G[MAX_V];
priority_queue<P,vector<P>,greater<P> >q;

void dijkstra(int s){
  fill(d,d+V,INF);
  d[s]=0;
  q.push(P(0,s));
  while(!q.empty()){
    P p=q.top();
    q.pop();
    int v=p.second;
    if(d[v]<p.first)continue;
    for(i=0;i<(int)G[v].size();i++){
      edge e=G[v][i];
      if(d[e.to]>d[v]+e.cost){
        d[e.to]=d[v]+e.cost;
        q.push(P(d[e.to],e.to));
      }
    }
  }
}

int main(){
  scanf("%d %d %d",&V,&E,&r);
  for(i=0;i<E;i++){
    scanf("%d %d %d",&s,&t,&c);
    edge e;
    e.to=t;e.cost=c;
    G[s].push_back(e);
  }
  dijkstra(r);
  for(i=0;i<V;i++){
    if(d[i]==INF)printf("INF\n");
    else printf("%d\n",d[i]);
  }
  return 0;
}

