#include<stdio.h>
int color[101],a[101][101],time,d[101],f[101];

void dfs(int u,int n){
  int v;
  color[u] = 1;
  time =1+time;
  d[u] = time;
  for(v=1;v<=n;v++){
    if(a[u][v] == 1 && color[v] ==0) dfs(v,n);
  }
  color[u] = 2;
   time =1+time;
  f[u] = time;
 
}
void dfs_in(int n){
  int i,u;
  for(i=1;i<=n;i++) color[i] = 0;
   time = 0;
  dfs(1,n);
   for(u=2;u<=n;u++){
     if(color[u] ==0) dfs(u,n);
  }
}
int main(){
  int n,i,j,k,v,id;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&id,&k);
     for(j=1;j<=n;j++) a[i][j] = 0;
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      a[id][v] =1; 
  }
    }
   dfs_in(n);
  for(i=1;i<=n;i++)
    printf("%d %d %d\n",i,d[i],f[i]);
  return 0;
}

