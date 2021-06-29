#include <stdio.h>
#define N 101
int A[N][N],d[N]={0},f[N]={0},n,cnt=0;

void find(u){
	int v;
  cnt++;
  d[u] = cnt;
  for(v=0; v<n; v++){
    if(A[u][v]==1 && d[v] == 0)
      find(v);
  }
  cnt++;
  f[u] = cnt;
}

int main(){
	int i,j,u,k,x;

  scanf("%d",&n);

  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      A[i][j] = 0;

  for(i=0; i<n; i++){
    scanf("%d%d",&u,&k);
    for(j=0; j<k; j++){
      scanf("%d",&x);
      A[u-1][x-1] = 1;
    }
  }

  for(i=0; i<n; i++){
    if(d[i] == 0)
      find(i);
  }

  for(i=0; i<n; i++)
    printf("%d %d %d\n",i+1,d[i],f[i]);

  return 0;
}
