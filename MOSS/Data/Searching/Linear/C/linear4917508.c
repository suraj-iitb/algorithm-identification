#include <stdio.h>

int linerSearch( int x, int n, int a[] ) {
  for( int i = 0; i < n; i++ ) {
    if(a[i] == x) return 1;
  }
  return 0;
}

int main(void) {
  int i, n, q, count = 0;
  int s[10000], t[500];

  scanf( "%d", &n );
  for( i = 0; i < n; i++ ) scanf( "%d", &s[i] );
  scanf( "%d", &q );
  for( i = 0; i < q; i++ ) scanf( "%d", &t[i] );

  for( i = 0; i < q; i++ ) {
    if(linerSearch( t[i], n, s )) count++;
  }

  printf( "%d\n", count );
  return 0;
}

