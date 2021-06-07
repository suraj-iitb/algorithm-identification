#include<stdio.h>

#define MAX 101

void Depth(int);

int G[MAX][MAX],D[MAX],d[MAX],f[MAX];
int n,count=1;

int main( ){
  int i,j,k,l,v,u;

  scanf("%d",&n);
  D[0] = 0;
  
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      G[u][v] = 1;
    }
  }

  for(i=0;i<n;i++){
    if(D[i]==0){
      Depth(i);
    }
  }
  
  for(i=0;i<n-1;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  printf("%d %d %d\n",i+1,d[i],f[i]);
  
  return 0;
}

  
void Depth(int a) {
  int b;

  d[a] = count++;
  D[a] = 1;
  
  for(b = 0 ; b < n ; b++) {
    if(G[a][b] == 1 && D[b] == 0) {
      Depth(b);
    }
  }
  
  f[a] = count++;
}

