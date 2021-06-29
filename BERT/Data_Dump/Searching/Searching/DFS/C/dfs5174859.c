#include<stdio.h>
#define N 100
int v[N][N];
int s[N],f[N], count = 0,n;

void dfs(int i){
  int j;
  count++;
  s[i]=count;
  for(j=0; j<n; j++){
    if(v[i][j] != 0 && s[j]==0){
      dfs(j);
    }
  }
  count++;
  f[i]=count;
}


int main(){
  int i, j, k, l, Adj[N+1];

  scanf("%d", &n);

  for(i = 0; i<n; i++){
    scanf("%d%d", &Adj[i], &k);
    if(k>0){
      for(j = 0; j<k; j++){
        scanf("%d", &l);
        v[Adj[i]-1][l-1] = 1;
      }
    }
  }

  for(i=0; i<n; i++){
    if(s[i] == 0)dfs(i);
  }

  for(i = 0;i<n; i++){
    printf("%d %d %d\n", i+1, s[i], f[i]);
  }

  return 0;
}
