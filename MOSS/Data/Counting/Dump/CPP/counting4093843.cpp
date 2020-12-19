#include <stdio.h>
#include <stdlib.h>

void CountingSort(int *,int *,int,int);

int main(){
  int n,i,k;
  int *A;
  int *B;
  k=0;
  scanf("%d",&n);
  A = (int *)malloc(n*sizeof(int)+2);
  B = (int *)malloc(n*sizeof(int)+2);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
    if(k < A[i]) k = A[i];
  }

  CountingSort(A,B,n,k);

  for(i=1; i<=n; i++){
    if(i != 1 )printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;
}

void CountingSort(int A[],int B[],int n,int k){
  int i,j;
  int *C;
  C =(int *)malloc(k*sizeof(int)+1);

  for(i=0; i<=k; i++) C[i]=0;

  for(j=0; j<n; j++) C[A[j]]++;

  for(i=0; i<k; i++) C[i+1] += C[i];

  for(j=n-1; j>=0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  
}

