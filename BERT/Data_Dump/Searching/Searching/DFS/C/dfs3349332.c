#include <stdio.h>
#define MAX 100

void dfs(int,int *,int *,int);

int f[MAX],d[MAX],Ad[MAX][MAX];

int main(){
  int n,i,j,u,k,v,visit,seacher[MAX];
  
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++) Ad[i][j] = 0;
  }

  for(i = 0;i < n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0;j < k;j++){
      scanf("%d",&v);
      Ad[u][--v] = 1;
    }
  }

  for(i = 0;i < n;i++) seacher[i] = 0;
  visit = 0;
  for(i = 0;i < n;i++) if(seacher[i] == 0) dfs(i,seacher,&visit,n);
  for(i = 0;i < n;i++) printf("%d %d %d\n",i + 1,d[i],f[i]);

  return 0;
}

void dfs(int i,int * seacher,int * visit,int n){
  int j;

  seacher[i] = 1;
  d[i] = ++*visit;
  for(j = 0;j < n;j++){
    if(Ad[i][j] == 0) continue;
    if(seacher[j] == 0) dfs(j,seacher,visit,n);
  }
  seacher[i] = 2;
  f[i] = ++*visit;
  
}

