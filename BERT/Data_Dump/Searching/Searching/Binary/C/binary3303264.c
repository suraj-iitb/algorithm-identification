#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *,int *, int, int);


int main() {
  int i, n, q, *S, *T;

  scanf( "%d" , &n );
  S = (int *)malloc((n+1) * sizeof(int));
  for( i=0; i<n; i++ ) scanf( "%d" , &S[i] );
  scanf( "%d" , &q );
  T = (int *)malloc(q * sizeof(int));
  for( i=0; i<q; i++ ) scanf( "%d" , &T[i] );

  printf( "%d\n" , binarySearch(S, T, n, q) );

  return 0;
}

int binarySearch(int *S, int *T, int n, int q) {
  int j, left, right, mid, count=0;

  for ( j=0; j<q; j++ ) {
    left = 0;
    right = n;
    while ( left < right ) {
      mid = (left + right) / 2;
      if ( S[mid] == T[j] ) {
	count++;
	break;
      }
      else if ( T[j] < S[mid] ) right = mid;
      else left = mid + 1;
    }
  }

  return count;
}

