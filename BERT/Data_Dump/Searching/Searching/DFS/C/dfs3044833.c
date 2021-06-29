#include <stdio.h>
 
int con[101][101]={0};
int d[101]={0};
int f[101]={0};
int used[101] = {0};
int n;
int cd = 0;



void dfs(int now)
{
  int i;
  cd++;
  d[now] = cd;
 
  for(i = 0; i < n; i++){
    if(con[now][i]){
       if(d[i] == 0){
    dfs(i);
       }
    }
  }
  cd++;
  f[now] = cd;
}
 
int main(void)
{
  int u, k, v;
  int i, j;

  
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d %d", &u, &k);
    u--;
    for(j = 0; j < k; j++){
      scanf("%d", &v);
      v--;
      con[u][v] = 1;
    }
  }
  for(i = 0; i < n; i++){
    if(d[i] == 0) dfs(i);
  }
  for(i = 0; i < n; i++)
    printf("%d %d %d\n", i+1, d[i], f[i]);
  return 0;
}

