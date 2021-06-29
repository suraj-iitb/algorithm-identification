#include <stdio.h>
#define MAX 2000000

void CountingSort(int);

int A[MAX+1], B[MAX+1], C[10000+1], n;

int main() {
  int i;

  scanf("%d", &n);
  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);


  CountingSort(10000);

  for ( i = 1; i <= n; i++ ) {
    printf("%d", B[i]);
    if ( i < n ) printf(" ");
  }
  printf("\n");

  return 0;
}

void CountingSort(int k) {
  int i, j;

  for ( i = 0; i <= k; i++ ) C[i] = 0;

  for ( j = 1; j <= n; j++ ) C[A[j]]++;

  for ( i = 1; i <= k; i++ ) C[i] = C[i] + C[i-1]; 

  for ( j = n; j >= 1; j-- ) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

}