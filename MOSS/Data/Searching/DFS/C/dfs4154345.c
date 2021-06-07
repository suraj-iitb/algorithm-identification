#include <stdio.h>
#define N 100
#define APEX 0
#define MID 1
#define BOTTOM 2

int n, M[N][N];
int color[N], d[N], f[N], tt;
void dfs_search(int m){
  int l;
  color[m]=MID;
  d[m]=++tt;
  for(l=0;l<n;l++){
    if(M[m][l]==0)continue;
    if(color[l]==APEX){
      dfs_search(l);
    }
  }
  color[m]=BOTTOM;
  f[m]=++tt;
}

void dfs(){
  int m;
  for(m=0;m<n;m++){
    color[m]=APEX;
    tt=0;
  }
  for(m=0;m<n;m++){
    if(color[m]==APEX) dfs_search(m);
  }
  for(m=0;m<n;m++){
    printf("%d %d %d\n", m+1, d[m], f[m]);
  }
}

int main(){
  int m, l, o, i, j;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d", &m, &o);
    m--;
    for(j=0;j<o;j++){
      scanf("%d", &l);
      l--;
      M[m][l]=1;
    }
  }
  dfs();
  return 0;
}
