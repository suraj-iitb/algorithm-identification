#include <stdio.h>
#define max 150

int arr[max][max];
int d[max],f[max];
int t = 0,n;

void dfs(int i){

  int j;
  t++;
  d[i] = t;

  for(j = 0 ; j < n ; j++){
    if(arr[i][j] != 0 && d[j] == 0)dfs(j);
  }

  t++;
  f[i] = t;
}


int main(){
  int i,j;
  int u,k,v;

  scanf("%d",&n);

  for(i  = 0 ; i < n ; i++){
    scanf("%d%d",&u,&k);
    for(j = 0 ; j < k ; j++){
      scanf("%d",&v);
      arr[u-1][v-1] =1;
    }
  }

  for(i = 0 ; i < n ; i++)if(d[i] == 0)dfs(i);

  for(i = 0 ; i < n ; i++)printf("%d %d %d\n",i+1 , d[i] , f[i]);
  return 0;
}
