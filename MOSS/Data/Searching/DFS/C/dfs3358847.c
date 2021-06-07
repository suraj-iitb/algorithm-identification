#include<stdio.h>
int G[101][101];
int n;
int m=1;
int A[101][2];

int dfs(int);

int main()
{
  int k,l,m,i,j;
  scanf("%d", &n);
  for(i=0;i<=n;i++){
    for(j=0;j<=n;j++) G[i][j]=0;
    A[i][0]=0;
    A[i][1]=0;
  }
  for(i=0;i<n;i++){
    scanf("%d", &m);
    scanf("%d", &k);
    for(j=0;j<k;j++){
      scanf("%d", &l);
      G[m][l] = 1;
    }
  }
  dfs(1);
  for(i=1;i<=n;i++){
    if(A[i][0]==0) dfs(i);
  }
  for(i=1;i<=n;i++) printf("%d %d %d\n", i, A[i][0], A[i][1]);
  return 0;
}

int dfs(int num)
{
  int l;
  if(A[num][0]==0){
    A[num][0]=m;
    m++;
  }
  for(l=0;l<=n;l++){
    if(G[num][l]==1&&A[l][0]==0) dfs(l);
  }
  if(A[num][1]==0){
    A[num][1]=m;
    m++;
  }
  return 0;
}

