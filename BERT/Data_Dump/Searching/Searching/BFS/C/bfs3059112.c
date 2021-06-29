#include<stdio.h>
#include<stdlib.h>

int t = 0;

typedef struct {
  int t1;
  int t2;
  int *v;
  int d;
  int k;
}DP;

void visit(DP *G, int i){
  int j;
  for(j=0; j<G[i].k; j++){
    if(G[G[i].v[j]-1].d > G[i].d || G[G[i].v[j]-1].d == -1){
      G[G[i].v[j]-1].d = 1 + G[i].d;
      visit(G, G[i].v[j]-1);
    }
  }

  return;
}

int main(){

  int n, i, j, u, k, l[100];
  DP *G;

  scanf("%d", &n);
  G = (DP *)malloc(sizeof(DP)*n);

  for(i=0; i<n; i++){
    scanf("%d%d", &u, &k);
    G[u-1].v = (int *)malloc(sizeof(int)*(k+1));
    G[u-1].k = k;
    G[u-1].d = -1;
    for(j=0; j<k; j++){
      scanf("%d", &G[u-1].v[j]);
    }
  }
  G[0].d = 0;
  visit(G, 0);

  for(i=0; i<n; i++){
    printf("%d %d\n", i+1, G[i].d);
  }

  return 0;
}
