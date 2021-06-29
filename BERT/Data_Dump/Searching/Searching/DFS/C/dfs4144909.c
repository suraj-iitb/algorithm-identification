#include<stdio.h>
#define INFTY 999999
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,M[MAX][MAX];
int color[MAX],d[MAX],f[MAX],p;

void dfs1(void);
void dfs2(int );

void dfs1(){
  int i,u;
  
  for(i=0;i<n;i++)color[i]=WHITE;
  p=0;
  for(u=0;u<n;u++){
    if(color[u]==WHITE)dfs2(u);

  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  
}

void dfs2(int u){
  int v;

  color[u]=GRAY;
  p++;
  d[u]=p;

  for(v=0;v<n;v++){
    if(M[u][v]==0)continue;
    if(color[v]==WHITE)dfs2(v);
  }
  color[u]=BLACK;
  f[u]=++p;
}

int main(){
  int i,j;
  int u,k,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
	}
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
	}
  }

  dfs1();
  return 0;
}

