#include <stdio.h>

int main(void)
{
   int N, i, j, minj, tmp;
   int wa = 0;
   int A[100];

   scanf("%d", &N);
   for ( i = 0; i < N; i++ ) {
      scanf("%d", &A[ i ]);
   }

   for ( i = 0; i < N - 1; i++ ) {
      minj = i;
      for ( j = i; j < N; j++ ) {
         if ( A[ minj ] > A [ j ] ) {
            minj = j;
         }
      }
      if ( i != minj ) {
         tmp = A[ i ];
         A[ i ] = A[ minj ];
         A[ minj ] = tmp;
         wa = wa + 1;
      }
   }

   for ( i = 0; i < N; i++ ) {
      if ( i > 0 ) {
         printf(" ");
      }
      printf("%d", A[ i ]);
   }
   printf("\n");
   printf("%d\n", wa);

   return 0;
}
