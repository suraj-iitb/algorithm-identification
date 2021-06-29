#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int n;

void CountingSort(int *,int *,int);
int main(){
  unsigned int *A, *B;
  int i,k=0;

  scanf("%d",&n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(k<A[i]){
      k = A[i];
    }
  }

  CountingSort(A,B,k);

  for(i=0;i<n-1;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n-1]);
  
  return 0;
}

void CountingSort(int *A,int *B,int k){
  int i,j,C[VMAX+1];

  for(i=0;i<=k;i++){
    C[i] = 0;
  }

  for(j=0;j<n;j++){
    C[A[j]]++;
  }

  for(i=1;i<=k;i++){
    C[i] = C[i]+C[i-1];
  }

  for(j=n-1;j>=0;j--){
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
  }
}
  

   

