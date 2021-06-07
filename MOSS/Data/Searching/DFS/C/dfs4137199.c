#include<stdio.h>

#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct{
  int k;
  int v[100];
}G;

void dfs(int);
void visit(int);

int time;
int d[MAX],f[MAX],color[MAX];
G Adj[101];

int main(){
  int i,j,k,n,u;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&Adj[u].k);
    for(j=0;j<Adj[u].k;j++) scanf("%d",&Adj[u].v[j]);
  }  
  
  dfs(n);

  for(i=1;i<=n;i++) printf("%d %d %d\n",i,d[i],f[i]);
  
  return 0;
}

void dfs(int u){
  int i;

  for(i=1;i<=u;i++) color[i]=WHITE;

  time=0;

  for(i=1;i<=u;i++){
    if(color[i]==WHITE) visit(i);
  }
}

void visit(int u){
  int a,i;
  
  color[u]=GRAY;
  d[u]=++time;

  for(i=0;i<Adj[u].k;i++){
    a=Adj[u].v[i];
    if(color[a]==WHITE) visit(a);
  }

  color[u]=BLACK;
  f[u]=++time;
}

