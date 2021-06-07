#include <stdio.h>
#define MAX 100
#define W 0
#define G 1
#define B 2

int n,A[MAX][MAX];
int C[MAX],a[MAX],b[MAX],d;

void dfsV(int k){
  int x;
  C[k]=G;
  a[k]=++d;
  for(x=0;x<n;x++){
    if(A[k][x]==0)
      continue;
    if(C[x]==W){
      dfsV(x);
    }
  }
  C[k]=B;
  b[k]=++d;
}

void df(){
  int k;
  for(k=0;k<n;k++)
    C[k]=W;
  d=0;

  for(k=0;k<n;k++){
    if(C[k]==W)
      dfsV(k);
  }
  for(k=0;k<n;k++){
    printf("%d %d %d\n",k+1,a[k],b[k]);
  }
}

int main(){
  int k,l,h,i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
      A[i][j]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&k,&h);
    k--;
    for(j=0;j<h;j++){
      scanf("%d",&l);
      l--;
      A[k][l]=1;
    }
  }

  df();

  return 0;
}

