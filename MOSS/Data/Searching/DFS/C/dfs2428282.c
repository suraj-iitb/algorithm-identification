#include<stdio.h>
#define N 100
#define White 0
#define Black 2
#define Gray 1

int n, M[N][N];
int color[N];
int d[N];
int f[N];
int time;
void DfsVisit(int );
void Dfs();
int main(){
  int i,j,u,k,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
      M[i][j]=0;
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
  Dfs();

  return 0;
}
void DfsVisit(int u){
  int v;
  color[u]=Gray;
  d[u]=++time;
  for(v=0;v<n;v++){
    if(M[u][v]==0)continue;
    if(color[v]==White){
      DfsVisit(v);
    }
  }
  color[u]=Black;
  f[u]=++time;
}
void Dfs(){
  int i;
  for(i=0;i<n;i++)color[i]=White;
  time=0;
  for(i=0;i<n;i++){
    if(color[i]==White)
	DfsVisit(i);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}
    
    
