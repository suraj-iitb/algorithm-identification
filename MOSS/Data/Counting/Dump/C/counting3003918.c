#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000
void CountingSort(int*,int*,int*,int,int);
int main(){
  int *A, *B;
  int C[VMAX+1];
  int n, i, j,max;

  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);
  
  for(i=1;i<n+1;i++)
    {
      scanf("%d",&A[i]);
      if(i==1) max = A[i];
      if(max < A[i]) max = A[i];
    }
  CountingSort(A,B,C,n,max);
  for(i=1;i<n;i++)
    {
      printf("%d ",B[i]);
    }
  printf("%d\n",B[i]);
  return 0;
}
void CountingSort(int *A,int *B,int *C,int n,int max){
  int i,j;
  for(i=0;i<=max;i++)
    {
      C[i]=0;
    }
  for(j=1;j<=n;j++)
    {
      C[A[j]]++;
    }
  for(i=1;i<=max;i++)
    {
      C[i]=C[i] + C[i-1];
    }
  for(j=n;j>0;j--)
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }
}

