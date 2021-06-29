#include<stdio.h>

#define N 101

int n,M[N][N];
int color[N],d[N],f[N],time;

void visit(int);

int main(){
  int i,j,v,vnext,k;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    color[i] = 0;
      for(j=0;j<n;j++){
	M[i][j] = 0;;
      }
  }
    
  for(i = 0;i<n;i++){
    scanf("%d %d",&v,&k);
    for(j=0;j<k;j++){
      scanf("%d",&vnext);
      M[v-1][vnext-1] = 1;
    }
  }

  for(i = 0;i<n;i++){
    if(color[i]==0)visit(i);
  }

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}

void visit(int u){

  int i;
  color[u]=1;
  d[u]=++time;
  for(i=0;i<n;i++){
    if(M[u][i] == 0)continue;
      if(color[i] == 0)visit(i);
    }
  color[u] = 2;
  f[u] = ++time;
}
  
