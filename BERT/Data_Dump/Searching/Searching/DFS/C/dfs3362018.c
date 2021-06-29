#include<stdio.h>
void DFS(int u);
int G=1,n,x[101][101],y[101]={0};
int d[101],f[101];

int main(void){
  int i,j,u,t,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      x[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&t);
    for(j=0;j<t;j++){
      scanf("%d",&v);
      x[u-1][v-1]=1;
    }
  }
  for(i=0;i<n;i++){
    if(y[i]==0){
      DFS(i);
    }
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}

void DFS(int id){
  int v;
  d[id]=G++;
  y[id]=1;
  for(v=0;v<n;v++){
    if(x[id][v]==1&&y[v]==0){
      DFS(v);
    }
  }
  f[id]=G++;
}

