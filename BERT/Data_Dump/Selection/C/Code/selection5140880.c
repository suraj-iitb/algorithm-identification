#include <stdio.h>
int main(void){
  int i, j, minj, k, N, tmp, a, b;
   k = 0;

  /*in*/
  scanf("%d", &N);
  int A[N];
  for (i=0; i<N; ++i){
    scanf("%d", &A[i]);
  }

  /*sort*/
   for(i = 0; i < N-1; i++){
      minj = i;
      a = 0;
      for(j = i; j < N; j++){
        if(A[j] < A[minj]){
          minj = j;
        }
      }
      if(i != minj){
        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        a = 1;
      }
     if(a == 1){
       k++;
     }
   }

  /*out*/
   for (i=0; i<N; ++i){
       if(i == N-1){
         printf("%d\n", A[i]);
       }else{
         printf("%d ", A[i]);
       }
   }
  printf("%d\n", k);
  return 0;
}
