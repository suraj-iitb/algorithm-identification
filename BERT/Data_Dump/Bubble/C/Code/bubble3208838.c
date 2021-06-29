#include <stdio.h>

int main(void){
   int N, i, j, k, x, m, f;

   scanf("%d", &N);

   int A[N];

   for(i = 0; i < N; i++) {
      scanf("%d", &A[i]);
   }

   m = 0;

   f = 1;

   if (N > 1){

   while(f == 1) {
     f = 0;
     for(j = N - 1; j > 0; j--){
        if (A[j] < A[j - 1]){
          x = A[j];
          A[j] = A[j - 1];
          A[j - 1] = x;
          m++;
          f = 1;
        }
     }
   }

   for(k = 0; k < N - 1; k++) {
      printf("%d ", A[k]);
   }
   printf("%d\n", A[N - 1]);

   printf("%d\n", m);

   } else {

   printf("%d\n", A[0]);

   printf("%d\n", m);

   }


   return 0;
}
