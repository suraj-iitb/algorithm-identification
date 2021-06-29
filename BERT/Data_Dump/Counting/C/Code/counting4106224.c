#include<stdio.h>
#include<stdlib.h>

#define k 10000

void CountingSort(int *,int);

int main(){
  int *A;
  int n;
  int i;

  /* Input */
  scanf("%d",&n);
  A=(int *)malloc((n)*sizeof(int)+1);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  CountingSort(A,n);

  free(A);

  return 0;
}

void CountingSort(int* A,int n){
  int C[k];
  int *B;
  int i,j;

  B=(int*)malloc(n*sizeof(int)+1);

  for(i=0;i<k;i++){
    C[i]=0;
  }

  /* C */
  for(j=0;j<n;j++){
    C[A[j]]++;
  }

  /* C' */
  for(i=1;i<k;i++){
    C[i]+=C[i-1];
  }

  for(j=n-1;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);
  free(B);
}

