#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define MAX_V 100001
#define INF (1e9 + 1)

struct edge{
  int to,cost;
};

int V,E,r,a,b,c;

vector< edge > G[MAX_V];


int d[MAX_V];
void dijkstra(){
  int i;
  for(i=0;i<MAX_V;i++)d[i]=INF;
  d[r]=0;
  priority_queue< pair<int,int> > Q;
  Q.push( make_pair(0,r) );
  while(!Q.empty()){
    pair<int,int> p=Q.top();
    Q.pop();
    int pos=p.second,cost=-p.first;
    if( cost > d[pos] )continue;
    for(i=0;i<G[pos].size();i++){
      edge e=G[pos][i];
      int to=e.to;
      int newcost=cost+e.cost;
      if( newcost < d[to]){
        d[to]=newcost;
        Q.push( make_pair(-d[to],to) );
      }
    }
  }

  for(i=0;i<V;i++){
    if(d[i]==INF)printf("INF\n");
    else printf("%d\n",d[i]);
  }
}

int main(){
  int i;
  scanf("%d %d %d",&V,&E,&r);
  for(i=0;i<E;i++){
    scanf("%d %d %d",&a,&b,&c);
    G[a].push_back((edge){b,c});
  }
  dijkstra();
  return 0;
}

