#include<stdio.h>
#include<stdlib.h>
#define N 10000

int main(){
  int n,i,j,k=0;
  unsigned short *A, *B;
  int C[N+1];
  
  scanf("%d",&n);

  A = malloc(sizeof(short) * n + 1);
  B = malloc(sizeof(short) * n + 1);

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }

  for(i=1;i<=n;i++){
    if(k < A[i]){
      k = A[i];
    }
  }

  for(i=0;i<k;i++){
    C[i] = 0;
  }
  
  for(j=1;j<=n;j++){
    C[A[j]] = C[A[j]] + 1;
  }
  
  for(i=1;i<=N;i++){
    C[i] = C[i] + C[i-1];
  }
  
  for(j=n;j>=1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]] - 1;
  }

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i < n ){
      printf(" ");
    }
  }
  printf("\n");

  return 0;
}


    
  

