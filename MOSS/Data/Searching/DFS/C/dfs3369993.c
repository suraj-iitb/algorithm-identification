#include<stdio.h>
#define N 100

int n,v[N][N],stat[N],d[N],f[N],time;
void dfs();
void dfs_init(int);

int main(){
  int u,b,i,j,m;
    scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      v[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&m);
    u--;
    for(j=0;j<m;j++){
      scanf("%d",&b);
      b--;
      v[u][b]=1;
    }
  }

  dfs();
  return 0;
}

void dfs(){
  int u;
  for(u=0;u<n;u++) stat[u]=0;
  time =0;

  for(u=0;u<n;u++){
    if(stat[u]==0) dfs_init(u);
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

void dfs_init(int m){
  int b;
  stat[m] =1;
  time++;
  d[m]= time;
  for(b=0;b<n;b++){
    if(v[m][b]==0) continue;
    if(stat[b]==0) dfs_init(b);

  }
  stat[m]=2;
  time++;
  f[m]= time;
}

