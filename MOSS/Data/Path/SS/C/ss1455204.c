#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX_V 100001
#define INF (1e9 + 1)

int V,E,r,a,b,c;
vector<int> G_t[MAX_V];
vector<int> G_c[MAX_V];

int d[MAX_V];
void dijkstra(){
  int i;
  for(i=0;i<MAX_V;i++)d[i]=INF;
  d[r]=0;
  priority_queue< pair<int,int> > Q;
  Q.push( make_pair(-d[r],r) );
  while(!Q.empty()){
    pair<int ,int > p=Q.top();
    Q.pop();
    int pos=p.second,cost=-p.first;
    if(cost > d[pos] )continue;
    for(i=0;i<G_t[pos].size();i++){
      int to=G_t[pos][i];
      int newcost=cost+G_c[pos][i];
      if(newcost <d[to]){
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
  scanf("%d%d%d",&V,&E,&r);
  for(i=0;i<E;i++){
    scanf("%d%d%d",&a,&b,&c);
    G_t[a].push_back(b);
    G_c[a].push_back(c);
  }
  dijkstra();
  return 0;
}
