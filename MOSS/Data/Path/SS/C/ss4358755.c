#include<queue>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
typedef pair<int,int> P;
struct edge{
    int to;
    int cost;
    edge(int t, int w) : to(t), cost(w) { }
};
int main(){
  int i,V,e,r,s,t,d;
  int ds[100010],ns[100010];
  int INF=2000000000;
  priority_queue<P,vector<P>,greater<P> > que;
  vector<vector<edge> > g(100010);
  scanf("%d %d %d\n",&V,&e,&r);
  for(i=0;i<e;i++){
    scanf("%d %d %d\n",&s,&t,&d);
    g[s].push_back(edge(t,d));
  }
  for(i=0;i<V;i++){
    ds[i]=INF,ns[i]=0;
  }
  ds[r]=0,ns[r]=1;
  que.push(P(0,r));
  while(!que.empty()){
    P p=que.top();
    que.pop();
    int v=p.second;
    if(ds[v]<p.first){
      continue;
    }
    for(i=0;i<g[v].size();i++){
      edge us=g[v][i];
      if(ds[us.to]>ds[v]+us.cost && ns[us.to]==0){
        ds[us.to]=ds[v]+us.cost;
        que.push(P(ds[us.to],us.to));
      }
    }
    ns[v]=1;
  }
  for(i=0;i<V;i++){
    if(ds[i]==INF){
      printf("INF\n");
      continue;
    }
    printf("%d\n",ds[i]);
  }
  return 0;
}
