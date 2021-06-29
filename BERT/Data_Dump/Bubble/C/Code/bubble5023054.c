#include<stdio.h>
int main(){
  int A[105], n, i, j, t, swap = 0;

  scanf("%d", &n);
  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);

  for ( i = 1; i <= n; i++ ){
    for ( j = n; j >= i+1; j-- ){
      if ( A[j] < A[j-1] ){
	t = A[j]; A[j] = A[j-1]; A[j-1] = t;
	swap++;
      }
    }
  }

  for ( i = 1; i <= n; i++ ){
    if (i>1) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", swap);

  return 0;
}

