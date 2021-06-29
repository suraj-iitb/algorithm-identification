#include <stdio.h>

int main(void)
{
   int N, i, j, tmp;
   int wa = 0;
   int A[100];

   scanf("%d", &N);
   for ( i = 0; i < N; i++ ) {
      scanf("%d", &A[ i ]);
   }

   for ( i = 0; i < N; i++ ) {
      for ( j = N - 1; j > 0; j-- ) {
         if ( A[ j ] < A[ j - 1 ] ) {
            tmp = A[ j ];
            A[ j ] = A[ j - 1 ];
            A[ j - 1 ] = tmp;
            wa = wa + 1;
         }
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
