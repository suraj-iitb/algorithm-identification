#include <stdio.h>

main(){

  int i, N;

  scanf("%d", &N);

  int A[N+1], key, j, p;

  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  for(i = 1; i < N+1; i++){
    for(p = 0; p < N; p++){
      if(p > 0) printf(" ");
      printf("%d", A[p]);
    }
    printf("\n");
    key = A[i];
    j = i - 1;
    while( j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
      A[j+1] = key;
    }
  }
  return 0;
}
