#include<stdio.h>

int d[100],f[100],G[100][100],color[100];
int time,n;


void visit(int);

int main(){

  int u,k,i,j,v;

  scanf("%d",&n);
  
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      G[i][j]=0;
  
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    if(k!=0)for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u-1][v-1]=1;
    }
  }

  for(i=0;i<n;i++)
    color[i]=0;
  time=0;

  for(i=0;i<n;i++){
    if(color[i]==0){
      visit(i);
    }}
  
  for(i=0;i<n-1;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  printf("%d %d %d\n",i+1,d[i],f[i]);
  
  return 0;

}

void visit(int u){

  int i;

  color[u] = 1;
  d[u] = ++time;
  for(i=0;i<n;i++){
    if(G[u][i]==1&&color[i]==0)
      visit(i);
  }
  color[u] = 2;
  f[u] = ++time;

}
