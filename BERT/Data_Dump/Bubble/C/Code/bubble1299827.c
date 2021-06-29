#include<stdio.h>
main(){
  int N, A[100], i, flag, a, x=0;
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  flag = 1;
  while(flag){
    flag = 0;
    for(i = N-1; 0 < i; i--){
      if(A[i] < A[i-1]){
	a = A[i];
	A[i] = A[i-1];
	A[i-1] = a;
	flag = 1;
	x++;
      }
    }
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
