#include <stdio.h>

typedef struct{
  int id;
  int color;
  int k;
  int next[100];
}Graph;

int n;
int S[100];
int top = 0;
int d[101],f[101];
int time;
Graph G[101] = {{0,0,0,NULL}};

void push(a){
  S[top]=a;
  top++;
}

int pop(){
  int a;
  a = S[top];
  if(top>0)
    top--;
  return a;
}

void visit(u){
  int i;
  G[u].color = 1;
  d[u] = ++time;
  for(i=0;i<G[u].k;i++){
    if(G[G[u].next[i]].color == 0)
      visit(G[u].next[i]);
  }
  G[u].color = 2;
  f[u] = ++time;
}

void dfs(){
  int i;
  time = 0;
  for(i=1;i<=n;i++){
    if(G[i].color == 0)
      visit(i);
  }
}

int main(){
  int i,j;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&G[i].id,&G[i].k);
    for(j=0;j<G[i].k;j++){
      scanf("%d",&G[i].next[j]);
    }
  }
  dfs();
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",G[i].id,d[i],f[i]);
  }

  return 0;
}

