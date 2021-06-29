#include <stdio.h>

int binarySearch( int x, int n, int a[] ) {
  int left = 0, right = n, mid;

  while( left < right ) {
    mid = (right+left) / 2;
    if( a[mid] == x ) return 1;
    else if( x < a[mid] ) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return 0;
}

int main(void) {
  int i, n, q, count = 0;
  int s[100000], t[50000];

  scanf( "%d", &n );
  for( i = 0; i < n; i++ ) scanf( "%d", &s[i] );
  scanf( "%d", &q );
  for( i = 0; i < q; i++ ) scanf( "%d", &t[i] );

  for( i = 0; i < q; i++ ) {
    if(binarySearch( t[i], n, s )) count++;
  }

  printf( "%d\n", count );
  return 0;
}

