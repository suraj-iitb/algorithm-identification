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
    int mini = i;

    for ( j = i + 1; j < n; ++j )
    {
      if ( d[ mini ] > d[ j ] )
      {
        mini = j;
      }
    }

    if ( i != mini )
    {
      swap ( d[ i ], d[ mini ] );
      ++res;
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
