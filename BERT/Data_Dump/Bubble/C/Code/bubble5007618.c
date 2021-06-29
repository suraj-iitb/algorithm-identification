#include<stdio.h>
int main(){
  int A[101], n, i, j, t, count;

  scanf("%d", &n);
  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);

  for ( i = 1; i <= n; i++ ){
    for ( j = n; j >= i+1; j-- ){
      if ( A[j] < A[j-1] ){
	t = A[j]; A[j] = A[j-1]; A[j-1] = t;
	count++;
      }
    }
  }

  for ( i = 1; i <= n; i++ ){
    if (i>1) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", count);

  return 0;
}
