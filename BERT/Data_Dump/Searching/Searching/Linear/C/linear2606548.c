#include <stdio.h>

int main(void)
{
   int n, S[1000000], q, T[1000000], i, j;
   int wa = 0;

   scanf("%d", &n);
   for ( i = 0; i < n; i++ ) {
      scanf("%d", &S[ i ]);
   }
   scanf("%d", &q);
   for ( i = 0; i < q; i++ ) {
      scanf("%d", &T[ i ]);
   }

   for ( i = 0; i < q; i++ ) {
      for ( j = 0; j < n; j++ )
         if ( T[ i ] == S[ j ] ) {
            wa = wa + 1;
            break;
         }
   }

   printf("%d\n", wa);

   return 0;
}
