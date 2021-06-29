#include <stdio.h>
#include <stdlib.h>

int linerSearch(int *,int *, int, int);


int main() {
  int i, n, q, *S, *T;

  scanf( "%d" , &n );
  S = (int *)malloc((n+1) * sizeof(int));
  for( i=0; i<n; i++ ) scanf( "%d" , &S[i] );
  scanf( "%d" , &q );
  T = (int *)malloc(q * sizeof(int));
  for( i=0; i<q; i++ ) scanf( "%d" , &T[i] );

  printf( "%d\n" , linerSearch(S, T, n, q) );

  return 0;
}


int linerSearch(int *S, int *T, int n, int q) {
  int i, j, key, count=0;

  for ( j=0; j<q; j++ ) {
    i=0;
    S[n] = T[j];
    while ( S[i] != T[j] ) i++;
    if ( i != n ) count++;
  }
  
  return count;
}

