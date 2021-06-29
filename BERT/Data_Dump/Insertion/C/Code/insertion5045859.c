#include<stdio.h>
#include<stdlib.h>

int main(){

  int A[100], N;
  int i, j, k, n;

  scanf("%d", &N);
  if(N < 1 || N > 100){
  exit(1);
  }

  for(i=0;i<N;i++){
    scanf("%d", &A[i]);
  }

  for(i=1;i<N;i++){
    for(k=0;k<N-1;k++) printf("%d ", A[k]);
    printf("%d\n", A[k]);
    n = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > n){
      A[j+1] = A[j];
      j--;
      A[j+1] = n;
    }
  }
  for(k=0;k<N-1;k++) printf("%d ", A[k]);
  printf("%d\n", A[k]);

  return 0;
}

