#include <stdio.h>

#define WHITE 1
#define GRAY 0
#define BLACK -1

void dfs(void);
void visit(int);

int f[102],d[102],color[102],time,n,vv[102][102],k[102];

int main()
{
  int i,j,u;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&u);

    scanf("%d",&k[u]);

    for(j=0;j<k[u];j++){
      scanf("%d",&vv[u][j]);
    }
  }

  dfs();

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }

  return 0;
}

void dfs(void){
  int u;
  for(u=1;u<=n;u++){
    color[u] = WHITE;
    time = 0;
  }
  for(u=1;u<=n;u++){

    if(color[u] == WHITE) visit(u);
  }
}

void visit(int u){
  int i,v;
  color[u] = GRAY;
  d[u] = ++time;
  for(i=0;i<k[u];i++){
    v=vv[u][i];
    if(color[v] == WHITE) visit(v);
  }
  color[u] = BLACK;
  f[u] = ++time;   
}
 
