#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001

void CountingSort(int *, int *,int);

int n;

int main()
{
  int i,j;
  int *A,*B;

  scanf("%d",&n);
  
  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);
  
  for(i = 0; i < n; i++){
    scanf(" %d",&A[i]);
  }

  CountingSort(A,B,10000);

  for(i = 1; i <= n; i++){
    if(i > 1)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  
  return 0;
}

void CountingSort(int A[], int B[],int k)
{
  int i,j,C[k+1];

  for(i = 0; i <= k; i++){
    C[i] = 0;
  }

  for(j = 0; j < n; j++){
    C[A[j]]++;
  }

  for(i = 1; i <= k; i++){
    C[i] = C[i] + C[i-1];
  }

  for(j = n-1; j >= 0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

