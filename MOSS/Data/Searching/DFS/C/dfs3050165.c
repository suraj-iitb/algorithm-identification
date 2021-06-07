#include<stdio.h>
#define N 100
#define white 0
#define gray 1
#define black 2

int n,M[N][N];
int color[N],d[N],f[N],t;

void dfsv(int u){
  int v;
  color[u]=gray;
  d[u]=++t;
  for(v=0;v<n;v++){
    if(M[u][v]==0)continue;
    if(color[v]==white){
      dfsv(v);
    }
  }
color[u]=black;
f[u]=++t;
}

void dfs(){
  int u;
  for(u=0;u<n;u++)color[u]=white;
  t=0;
  for(u=0;u<n;u++){
    if(color[u]==white)dfsv(u);
  }
for(u=0;u<n;u++){
  printf("%d %d %d\n",u+1,d[u],f[u]);
}
}

int main(){
  int u,v,k,i,j;
scanf("%d",&n);
for(i=0;i<n;i++){
  for(j=0;j<n;j++)M[i][j]=0;
}
for(i=0;i<n;i++){
  scanf("%d %d",&u,&k);
u--;
for(j=0;j<k;j++){
  scanf("%d",&v);
  v--;
  M[u][v]=1;
}
}
dfs();
return 0;
  }

