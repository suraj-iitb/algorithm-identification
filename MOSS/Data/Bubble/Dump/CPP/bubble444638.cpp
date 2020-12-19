#include <cstdio>
#include <algorithm>

#define N 100

using namespace std;

int
main ( )
{
  int res = 0;
  int d[ N ];
  int n;
  int i, j;

  scanf ( "%d", &n );
  for ( i = 0; i < n; ++i )
  {
    scanf ( "%d", &d[ i ] );
  }

  for ( i = 0; i < n; ++i )
  {
    for ( j = n - 1; j > i; --j )
    {
      if ( d[ j - 1 ] > d[ j ] )
      {
        swap ( d[ j - 1], d[ j ] );
        ++res;
      }
    }
  }

  for ( i = 0; i < n; ++i )
  {
    if ( i ) putchar ( ' ' );
    printf ( "%d", d[ i ] );
  }
  printf ( "\n%d\n", res );

  return ( 0 );
}
