#include<stdio.h>
main(){
  int N, A[100], i, j, minj, a, x=0, y=0;
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(A[j] < A[minj]){
	minj = j;
	y = 1;
      }
    }
    a = A[i];
    A[i] = A[minj];
    A[minj] = a;
    x += y;
    y = 0;
  }
  
  for(i = 0; i < N; i++){
    if(i == N-1){
      printf("%d\n", A[i]);
    }
    else  printf("%d ", A[i]);
  }
  printf("%d\n", x);
  return 0;
}
