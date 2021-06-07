
#include<stdio.h>
#include<stdlib.h>
#define N 100
int n,t;
int g[N][N],c[N],d[N],f[N];
void V(int);
void D();

int main(){
  int i,j;
  int u,v,k;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      g[i][j]=0;
    }
  }

  for(i=0; i<n; i++){
    scanf("%d%d",&u,&k);
    for(j=0; j<k; j++){
      scanf("%d",&v);
      g[u-1][v-1]=1;
    }
  }

  D();
  for(i=0; i<n; i++)
    printf("%d %d %d\n",i+1,d[i],f[i]);

  return 0;
}

void V(int u){
  int i;
  c[u]=1;
  d[u]=++t;
  for(i=0; i<n; i++){
    if(g[u][i]==0) continue;
    if(c[i]==0) V(i);
  }
  c[u] = 2;
  f[u]= ++t;
}

void D(){
  int i;
  for(i=0; i<n; i++) c[i]=0;
  t = 0;
  for(i=0; i<n; i++){
    if(c[i] == 0) V(i);
  }
}

