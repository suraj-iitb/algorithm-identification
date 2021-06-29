  #include<stdio.h>
  #define N 100
  #define WHITE 0
  #define GRAY 1
  #define BLACK 2

  int num,M[N][N];
  int t,color[N],d[N],f[N];

  void dfs_vist(int a){
    int v;
    color[a]=GRAY;
    d[a]=++t;
    for(v=0;v<num;v++){
      if(M[a][v]==0)continue;
      if(color[v]==WHITE){
        dfs_vist(v);
      }
    }
    color[a]=BLACK;
    f[a]=++t;
  }
  void dfs(){
    int u;
    for(u=0;u<num;u++)color[u]=WHITE;
    t=0;
    for(u=0;u<num;u++){
      if(color[u]==WHITE)dfs_vist(u);
    }
    for(u=0;u<num;u++){
      printf("%d %d %d\n",u+1,d[u],f[u]);
    }
  }

  int main(){
    int i,j,u,v,k;
    scanf("%d",&num);
    for(i=0;i<num;i++){
      for(j=0;j<num;j++){
        M[i][j]=0;
      }
    }
    for(i=0;i<num;i++){
      scanf("%d%d",&u,&k);
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

