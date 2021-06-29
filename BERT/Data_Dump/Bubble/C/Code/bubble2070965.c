#include <stdio.h>

int main(){

  int A[100];
  int flag = 1;
  int times = 0;
  int i, j, k, N, B;
  
  scanf("%d", &N);
  for ( i = 0; i <= N - 1; i++){
    scanf("%d", &A[i]);
  }
  
  //bubbleSort
  while(flag == 1){
    flag = 0;
    for ( j = N - 1; j >= 1; j--){
      if( A[j] < A[j-1]){
        B = A[j];
        A[j] = A[j-1];
        A[j-1] = B;
        times = times + 1;
        flag = 1;
      }
    }
  }
   
  //OutPut
  for ( i = 0; i <= N - 2; i++){
    printf("%d ", A[i]);
  }
  printf("%d\n", A[N-1]);
  printf("%d\n", times);
  
  return 0;
}
  
