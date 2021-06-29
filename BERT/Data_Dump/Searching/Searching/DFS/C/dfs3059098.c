#include<stdio.h>
#include<stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK -1

int t = 0;

typedef struct {
  int t1;
  int t2;
  int *v;
  int color;
  int k;
}DP;



void dfs(DP *G, int n){
  int i;
  for(i=0; i<n; i++){
    G[i].color = WHITE;
  }
    for(i=0; i<n; i++){
      if(G[i].color == WHITE){
        visit(G, i);
      }
    }
}

void visit(DP *G, int i){
  int j;
  G[i].color = GRAY;
  G[i].t1 = ++t;
  for(j=0; j<G[i].k; j++){
    //printf("%d\n", G[i].v[j]);
    //printf("%d--------------------\n", G[G[i].v[j]].color);
    if(G[G[i].v[j]-1].color == WHITE){
      visit(G, G[i].v[j]-1);
    }
  }
  G[i].color = BLACK;
  G[i].t2 = ++t;
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
    for(j=0; j<k; j++){
      scanf("%d", &G[u-1].v[j]);
    }
  }

  dfs(G, n);

  for(i=0; i<n; i++){
    printf("%d %d %d\n", i+1, G[i].t1, G[i].t2);
  }

  return 0;
}
