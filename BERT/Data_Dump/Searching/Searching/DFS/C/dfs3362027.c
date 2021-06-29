#include<stdio.h>

#define N 101

void dfs(int u);

int G=1,n,a[N][N],b[N];
int d[N],f[N];

int main(void){
  int i,j,u,t,v;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&t);
    for(j=0;j<t;j++){
      scanf("%d",&v);
      a[u-1][v-1]=1;
    }
  }
  for(i=0;i<n;i++){
    if(b[i]==0){
      dfs(i);
    }
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}

void dfs(int id){
  int v;
  d[id]=G++;
  b[id]=1;
  for(v=0;v<n;v++){
    if(a[id][v]==1&&b[v]==0){
      dfs(v);
    }
  }
  f[id]=G++;
}

