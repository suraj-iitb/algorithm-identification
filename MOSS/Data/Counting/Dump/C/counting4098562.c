#include<stdio.h>
#include<stdlib.h>
#define M 10000

void CountingSort(int *,int *,int,int);
int main(){
  int *A,*B,n,i;
  int max=0;
  scanf("%d",&n);
  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);
  for(i=1;i<=n;i++)
    scanf("%d",&A[i]);
  
  CountingSort(A,B,M,n);
  for(i=1;i<n;i++)
    printf("%d ",B[i]);
  printf("%d\n",B[i]);
  return 0;
}

void CountingSort(int *A,int *B,int k,int n){
  int C[k+1],i,j;
  for(i=0;i<=k;i++)
    C[i]=0;

  for(j=1;j<=n;j++)
    C[A[j]]++;

  for(i=1;i<=k;i++)
    C[i]+=C[i-1];

  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}

