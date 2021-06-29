#include<stdio.h>

int main(){
  int A[110], n, i, j, t, temp = 0;

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);

  for ( i = 0; i < n; i++ ){
    for ( j = n-1; j >= i+1; j-- ){
      if ( A[j] < A[j-1] ){
	t = A[j]; A[j] = A[j-1]; A[j-1] = t;
	temp++;
      }
    }
  }

  for ( i = 0; i < n; i++ ){
    if (i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", temp);

  return 0;
}

