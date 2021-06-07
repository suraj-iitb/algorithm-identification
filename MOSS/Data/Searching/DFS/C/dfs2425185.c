#include <stdio.h>
int DFS(int);
int A[100][2],a[100][100];
int t=0;
int n;
int main(){
  int i,j,u,k,v;
  scanf("%d",&n);
  for(i=0;i<100;i++)
    for(j=0;j<100;j++)
      a[i][j]=0;
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      a[u-1][v-1]=1;
    }
  }
  for(i=0;i<n;i++)
    if(A[i][0]==0){
      t++;
      DFS(i);
    }
  for(i=0;i<n;i++)
    printf("%d %d %d\n",i+1,A[i][0],A[i][1]);
  return 0;
}

int DFS(int m){
  int i;
  A[m][0]=t;
  for(i=0;i<n;i++)
    if(a[m][i]==1&&m!=i&&A[i][0]==0){
      t++;
      DFS(i);
    }
  t++;
  A[m][1]=t;
  return 0;
}
