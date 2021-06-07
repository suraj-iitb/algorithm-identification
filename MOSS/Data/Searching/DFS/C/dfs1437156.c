#include<stdio.h>
#define N 102

int g[N][N];
int d[N],f[N];
int t=0,n=0;
 
int D(int x){
  t++;
  int i;
  for(i=1;i<=n;i++){
    if(d[x]==0)
      d[x] = t;
    if(g[x][i]==1 && f[i]==0){
      g[x][i]=0;
      if(d[i]==0){
    D(i);
    t++;
      }
    }
    if(i==n && f[x]==0){
      f[x] = t+1;
    }
  }
  return 0;
}
 
int main(){
  scanf("%d", &n);
  int i,j;
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      g[i][j] = 0;
    }
    d[i]=0;
    f[i]=0;
  }
 
  int l,k;
  for(i=0;i<n;i++){
    scanf("%d %d", &l,&k);
    for(j=0;j<k;j++){
      int v;
      scanf("%d", &v);
      g[l][v] = 1;
    }
  }
 
  for(i=1;i<=n;i++){
    if(f[i]==0){
      D(i);
      t++;
    }
  }
  for(i=1;i<=n;i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }
  return 0;
}
