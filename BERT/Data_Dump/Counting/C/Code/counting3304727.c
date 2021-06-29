#include<stdio.h>
#include<stdlib.h>

#define k 10001

void CountingSort(int *,int *,int);

int main(){
  int i,n,*A,*B;

  scanf("%d",&n);
  A=(int *)malloc(n*sizeof(int));
  B=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  
  CountingSort(A,B,n);

  for(i=0;i<n;i++){
    printf("%d",B[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");

  free(A);
  free(B);

  return 0;
}

void CountingSort(int *A,int *B,int n){
  int i;
  int *C;
  
  C=(int *)malloc(k*sizeof(int));
  for(i=0;i<k;i++) C[i]=0;

  for(i=0;i<n;i++) C[A[i]]++;

  for(i=1;i<k;i++) C[i]=C[i]+C[i-1];

  for(i=n-1;i>=0;i--){
    B[C[A[i]]-1]=A[i];
    C[A[i]]--;
  }

  free(C);
}

