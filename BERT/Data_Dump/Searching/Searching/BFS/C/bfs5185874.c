#include <stdio.h>
#define MAX 100
#define ML 10000000

int G[MAX+1][MAX+1],d[MAX+1],n,size[MAX+1];

void msho(int p, int t){
  int id;
  d[p] = t;
  for(id=1;id<=size[p];id++)
    if(t+1 < d[G[p][id]]) msho(G[p][id],t + 1);
}

int main(){
  int id,l,u;
  scanf("%d",&n);
  for(id=1;id<=n;id++){
    d[id] = ML;
    scanf("%d",&u);
    scanf("%d",&size[u]);
    for(l=1;l<=size[u];l++)
      scanf("%d",&G[u][l]);
  }
  msho(1, 0);
  for(id=1;id<=n;id++)
    printf("%d %d\n",id,(d[id] == ML) ? -1 : d[id]);
  return 0;
}
