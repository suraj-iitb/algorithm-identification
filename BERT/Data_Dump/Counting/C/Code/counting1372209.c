#include <stdio.h>
#include <stdlib.h>

#define length_c 10001


void countingSort( int *a, int *b, int n) {
  
  int i, j;
  int *c;

  c = malloc( sizeof(int) * (length_c) );

  for( i=0; i<length_c; i++) {
    c[i] = 0;
  }
  
  for( j=1; j<=n; j++) {
    c[ a[j] ]++;
  }

  for( i=1; i<length_c; i++) {
    c[i] = c[i] + c[i-1];
  }

  for( j=n; j>=1; j--) {
    b[ c[ a[j] ] ] = a[j];
    c[ a[j] ]--;
  }

}


main() {
  
  int i;
  int n;
  int *a, *b;


  scanf("%d", &n);

  a = malloc( sizeof(int) * (n+1) ); //1オリジンの配列
  for( i=1; i<=n; i++) {
    scanf( "%d", &a[i]);
  }

  b = malloc( sizeof(int) * (n+1) ); //ソートした配列aを格納する配列

  countingSort( a, b, n);

  for( i=1; i<n; i++) {
    printf("%d ", b[i]);
  }
  printf("%d\n", b[i]);

  return 0;

}
