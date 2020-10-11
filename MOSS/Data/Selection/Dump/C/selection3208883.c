#include <stdio.h>

int main(void){
   int N, i, j, k, x, m, minj;

   scanf("%d", &N);

   int A[N];

   for(i = 0; i < N; i++) {
      scanf("%d", &A[i]);
   }

   m = 0;

   for(i = 0; i < N; i++){
      minj = i;
      for(j = i; j < N; j++){
         if (A[j] < A[minj]){
            minj = j;
         }
      }
      if (minj != i){
            x = A[i];
            A[i] = A[minj];
            A[minj] = x;
            m++;
      }
   }

   for(k = 0; k < N - 1; k++) {
      printf("%d ", A[k]);
   }
   printf("%d\n", A[N - 1]);

   printf("%d\n", m);

   return 0;
}
