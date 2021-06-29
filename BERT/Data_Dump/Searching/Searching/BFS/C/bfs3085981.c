#include <stdio.h>
#include <math.h>
#define C 100
#define INF 1000000
int G[C+1][C+1];
int l[C+1];
int E[C+1];
void Search(int pi,int t){
  int i;
  E[pi]=t;
  for(i=1;i<=l[pi];++i){
    if(t+1<E[G[pi][i]]){
      Search(G[pi][i],t+1);
    }
  }
}
int main(){
  int x,n,i,j;
  scanf("%d",&n);
  for(i=1;i<=n;++i){
    E[i]=INF;
    scanf("%d",&x);
    scanf("%d",&l[x]);
    for(j=1;j<=l[x];++j)scanf("%d",&G[x][j]);
  }
    Search(1,0);
    for(i=1;i<=n;++i)printf("%d %d\n",i,(E[i]==INF) ? -1 :E[i]);
    return 0;
  }


    
