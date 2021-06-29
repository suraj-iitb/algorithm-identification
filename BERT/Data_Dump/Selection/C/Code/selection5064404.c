#include<stdio.h>

int main(){
  int A[100], i, j, n, t, sw = 0, m;

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);

  for ( i = 0; i < n; i++ ){
    m = i;
    for ( j = i; j < n; j++ ){
      if ( A[j] < A[m] ) m = j;
    }
    t = A[i]; A[i] = A[m]; A[m] = t;
    if ( i != m ) sw++;
  }

  for ( i = 0; i < n; i++ ){
    if (i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", sw);

  return 0;
}

