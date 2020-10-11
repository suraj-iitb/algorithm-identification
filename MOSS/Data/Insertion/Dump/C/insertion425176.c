#include <stdio.h>

#define N 100

/** Application main entry point. */
int
main (
  int     argc,
  char  * argv[ ]
  )
{
  int d[ N ];
  int n;
  int i, j;

  scanf ( "%d", &n );
  for ( i = 0; i < n; ++i )
  {
    scanf ( "%d", &d[ i ] );
  }

  for ( j = 1; ; ++j )
  {
    int k;

    for ( i = 0; i < n; ++i )
    {
      if ( i ) putchar ( ' ' );
      printf ( "%d", d[ i ] );
    }
    puts ( "" );
    if ( j >= n ) break ;

    k = d[ j ];
    for ( i = j; i > 0 && d[ i - 1 ] > k; --i )
    {
      d[ i ] = d[ i - 1 ];
    }
    d[ i ] = k;
  }

  return ( 0 );
}
