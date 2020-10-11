#include <stdio.h>
#include<stdlib.h>
#define N 10000

int main(){
  unsigned short *A, *B;

  int C[N];
  int n, i, j;
  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i = 0;i < N;i++ ){
    C[i] = 0;
  }
  for (i = 0;i < n; i++ ){
    scanf("%hu",&A[i+1]);
    C[A[i+1]]++;
  }
  for (i = 1;i < N+1;i++ ){
    C[i] = C[i] + C[i-1];
  }
  for (j = 1;j < n+1;j++ ){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for (i = 1;i < n+1;i++ ){
    if ( i < n){ 
    printf("%d ",B[i]);
    }
    else if(i == n){
      printf("%d\n",B[i]);
    }
  }
 
  return 0;
}
