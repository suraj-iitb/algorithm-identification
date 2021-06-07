#include<stdio.h>
#define N 100
#define SHIRO 0
#define GRAY 1
#define KURO 2

int kazu,M[N][N];
int color[N],d[N],f[N],tt;

void visit(int u){
  int v;
  color[u]=GRAY;
  d[u]=++tt;
  for(v=0;v<kazu;v++){
    if(M[u][v]==0)continue;
    if(color[v]==SHIRO){
      visit(v);
    }
  }
  color[u]=KURO;
  f[u]=++tt;
}
void x(){
  int u;
  for(u=0;u<kazu;u++)color[u]=SHIRO;
  tt=0;
  for(u=0;u<kazu;u++){
    if(color[u]==SHIRO)visit(u);
  }
  for(u=0;u<kazu;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}
int main()
{
  int u,v,k,i,j;
  scanf("%d",&kazu);
  for(i=0;i<kazu;i++){
    for(j=0;j<kazu;j++)M[i][j]=0;
  }
  for(i=0;i<kazu;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }
  x();
  return 0;
}

