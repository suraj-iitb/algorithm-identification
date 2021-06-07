#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
void dfs(void);
void dfs_v(int);
int n,M[N][N];
int color[N],d[N],f[N],time;


int main(){
  int u,k,v;
  int i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf(" %d%d",&u,&k);
    u-=1;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }

  dfs();
  return 0;
}

void dfs(){
  int u;
  for(u=0;u<n;u++){
    color[u]=WHITE;
  }

  time=0;


  for(u=0;u<n;u++){
    if(color[u]==WHITE)dfs_v(u);
  }


  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}


void dfs_v(int u){
  int v;
  color[u]=GRAY;
  time+=1;
  d[u]=time;
  for(v=0;v<n;v++){
    if(M[u][v]==0)continue;
    if(color[v]==WHITE){
      dfs_v(v);
    }
  }
  color[u]=BLACK;
  time+=1;
  f[u]=time;
}
