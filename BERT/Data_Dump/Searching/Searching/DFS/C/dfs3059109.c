#include <stdio.h>
int m[100][100];
int f[100];
int d[100];
int n;
int t;
 
 
 
void visit(int u){
  int v;
  d[u] = ++t;
  for(v=0;v<n;v++){
    if(m[u][v] && d[v] == 0){
      visit(v);
    }
  }
    f[u] = ++t;
}
 
int main (){
  int i,j,k,u,r;
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    d[i] = 0;
    f[i] = 0;
    for(j=0;j<n;j++){
      m[i][j] = 0;
    }
  }
 
  for(i=0;i<n;i++){
    scanf("%d",&r);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&u);
      m[r-1][u-1] = 1;
    }
  }
  t = 0;
  for(i=0;i<n;i++){
    if(d[i] == 0){
      visit(i);
    }
  }
 
 
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}

