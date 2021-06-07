#include<stdio.h>

#define MAX 101
#define WHITE 0
#define GRAY -1
#define BLACK 1

typedef struct{
  int id;
  int k;
  int color;
  int adj[MAX];
}Graph;

void DFS(void);
void DFSvisit(Graph);
Graph G[MAX];
int d[MAX];
int f[MAX];
int color[MAX];
int n,time;

int main(){
  int u,k,i,j,tmp;
  for(i=1;i<MAX;i++){
    for(j=1;j<MAX;j++){
      G[i].adj[j]=0;
    }
  }
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k);
    G[u].id=u;
    G[u].k=k;
    for(j=1;j<=k;j++){
      scanf("%d",&tmp);
      G[u].adj[j]=tmp;
    }
  }
  DFS();
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;

}

void DFS(){
  int i;
  for(i=1;i<=n;i++){
    G[i].color=WHITE;
  }
  time=0;
  for(i=1;i<=n;i++){
    if(G[i].color==WHITE)DFSvisit(G[i]);
  }
}

void DFSvisit(Graph U){
  int i;
  G[U.id].color=GRAY;
  time++;
  d[U.id]=time;

  for(i=1;i<=U.k;i++){
    if(G[U.adj[i]].color==WHITE){
      DFSvisit(G[U.adj[i]]);
    }
  }
  G[U.id].color=BLACK;
  time++;
  f[U.id]=time;
}
