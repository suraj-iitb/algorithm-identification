#include <stdio.h>
#include <stdlib.h>
#define N 2000000
#define K 10000

void CountingSort(int *,int *,int);

int n;

int main()
{
  int i,*A,*B;

  scanf("%d",&n);
  if(n<1 || n>N) exit(1);

  A = (int *)malloc(sizeof(int)*n);
  B = (int *)malloc(sizeof(int)*n);
  
  for(i=0;i<n;i++){
    scanf(" %d",&A[i]);
    if(A[i]<0 || A[i]>10000) exit(2);
  }

  CountingSort(A,B,K);

  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",B[i]);
  }
  
  printf("\n");
  
  return 0;
}

void CountingSort(int *A,int *B,int k)
{
  int i,j,C[K];

  for(i=0;i<k;i++)
    C[i] = 0;

  for(j=0;j<n;j++)
    C[A[j]]++;

  for(i=1;i<k;i++)
    C[i] += C[i-1];

  for(j=n-1;j>=0;j--){
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
    /*for(i=0;i<n;i++) printf("%d ",B[i]);
      printf("\n");*/
  }
}

