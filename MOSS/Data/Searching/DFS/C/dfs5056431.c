#include<stdio.h>

void Dfs(int u);

int A[100][100] = {0};
int n;
int d[100],f[100];
int t = 1;

int main(void){
  int i,j,u,k,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      A[u-1][v-1]=1;
    }
  }

  for(i=0;i<n;i++){
    if(d[i]==0){
      Dfs(i);
    }
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}

void Dfs(int u){
  int v;
  d[u]=t++;
  for(v=1;v<=n;v++){
    if(A[u][v] == 1 && d[v]==0){
      Dfs(v);
    }
  }
  f[u]= t++;
}

