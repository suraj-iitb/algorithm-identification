#include<stdio.h>
#define N 100
#define White 0
#define Gray 1
#define Brack 2

int n,A[N][N],c[N],d[N],f[N],t;

void dfsst(int x){
  int v;
  c[x]=Gray;
  d[x]=++t;
  for(v=0;v<n;v++){
    if(A[x][v]==0)continue;
    if(c[v]==White){
      dfsst(v);
    }
  }
  c[x]=Brack;
  f[x]=++t;
}

void dfs(){
  int i;
  for(i=0;i<n;i++){
    c[i]=White;
  }
  t=0;

  for(i=0;i<n;i++){
    if(c[i]==White)dfsst(i);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}
int main(){
  int u,v,k,i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j]=0;
           }
    }
    for(i=0;i<n;i++){
      scanf("%d %d",&u,&k);
      u--;
      for(j=0;j<k;j++){
        scanf("%d",&v);
        v--;
        A[u][v]=1;
      }
    }
    dfs();

    return 0;
  }




