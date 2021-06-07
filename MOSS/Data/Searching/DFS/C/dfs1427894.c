#include<stdio.h>

typedef struct{
  int a;
  int m;
  int N[100];
  int dis;
  int fin;
  int count;
} Graph;

int way = 1;
Graph G[101];

void DepthFirstSearch(int x){
  int i;

  if(G[x].count == 0){
    G[x].count++;
    G[x].dis = way;
    way++;
  }

  for(i = 0; i < G[x].m; i++){
    if(G[G[x].N[i]].count == 0) DepthFirstSearch(G[x].N[i]);
  }

  if(G[x].fin == 0){
    G[x].fin = way;
    way++;
  }
}

int main(){
  int n, m, i, j;

  scanf("%d", &n);

  for(i = 1; i <= n; i++){
    scanf("%d%d", &G[i].a, &G[i].m);
    G[i].count = G[i].dis = G[i].fin = 0;

    for(j = 0; j < G[i].m; j++) scanf("%d", &G[i].N[j]);
  }

  for(i = 1; i <= n; i++) DepthFirstSearch(G[i].a);

  for(i = 1; i <= n; i++) printf("%d %d %d\n", G[i].a, G[i].dis, G[i].fin);

  return 0;
}
