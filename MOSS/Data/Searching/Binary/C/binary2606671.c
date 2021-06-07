#include <stdio.h>

   int A[1000000], n;

int search(int a) 
{
   int l = 0;
   int r = n;
   int m;

   while ( l < r ) {
      m = ( l + r ) / 2;
      if ( a == A[ m ] ) return 1;
      if ( a > A[ m ] ) l = m + 1;
      else if ( a < A[ m ] ) r = m;
   }
   return 0;
}

int main()
{
   int i, q, a;
   int wa = 0;

   scanf("%d", &n);
   for ( i = 0; i < n; i++ ) {
      scanf("%d", &A[ i ] );
   }
   scanf("%d", &q);

   for ( i = 0; i < q; i++ ) {
      scanf("%d", &a);
      if ( search( a ) ) {
         wa = wa + 1;
      }
   }
   printf("%d\n", wa);

   return 0;
} 

   
