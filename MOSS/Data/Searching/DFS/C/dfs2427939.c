  #include<stdio.h>
  #define N 100
  #define SHIRO 0
  #define HAI 1
  #define KURO 2

  int n,M[N][N];
  int iro[N],f[N],d[N],tt;

  void vdepth(int u){
    int v;
    iro[u]=HAI;
    d[u]=++tt;
    for(v=0;v<n;v++){
      if(M[u][v]==0)continue;
      if(iro[v]==SHIRO){
        vdepth(v);
      }
    }
    iro[u]=KURO;
    f[u]=++tt;
  }

  void def(){
    int u;
    for(u=0;u<n;u++)iro[u]=SHIRO;
    tt=0;
    for(u=0;u<n;u++){
      if(iro[u]==SHIRO)vdepth(u);
    }
    for(u=0;u<n;u++){
      printf("%d %d %d\n",u+1,d[u],f[u]);
    }
  }

  int main(){
    int u,v,k;

    scanf("%d",&n);
    int i,j;
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

    def();
    return 0;
  }
