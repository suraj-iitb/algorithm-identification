#include<stdio.h>
#define INF 100000000
int A[101][101];
int P[101];
int n;
void bfs(int s,int c){
  int i;
  for(i=0;i<n;i++){
    if(A[s][i+1]==1 && P[i+1] > c){
      P[i+1] = c;
      bfs(i+1,c+1);
    }
  }
}
int main(){
  int i,j;
  int u,k,v;
  for(i=0;i<100;i++){
    P[i+1] = INF;
  }
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      A[u][v] = 1;
    }
  }
  P[1]=0;
  bfs(1,1);
  for(i=0;i<n;i++){
    printf("%d ",i+1);
    if(P[i+1]==INF) printf("-1");
    else printf("%d",P[i+1]);
    printf("\n");
  }
  return 0;
}

