#include <stdio.h>

void dfs();
void visit(int);

int time,n,color[100],d[100],f[100],A[100][100];

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++) A[i][j]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      A[u-1][v-1]=1;
    }
  }
  dfs();

  for(i=0;i<n;i++) printf("%d %d %d\n",i+1,d[i],f[i]);

  return 0;
}

void dfs(){
  int i;

  for(i=0;i<n;i++) color[i]=0;
  time=0;
  for(i=0;i<n;i++){
    if(color[i]==0) visit(i);
  }
}

void visit(int u){
  int i,j;
  
  color[u]=1;
  d[u]=++time;

  for(j=0;j<n;j++){
    if(A[u][j]==1&&color[j]==0) visit(j);
  }

  color[u]=2;
  f[u]=++time;
}
