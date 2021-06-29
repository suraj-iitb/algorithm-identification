#include<stdio.h>
#include<stdlib.h>

int main() {
  int n, i, j;
  int c = 0;
  int temp;
  int *A;

  scanf("%d", &n);
  A = malloc(n*sizeof(int));
  for(i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  for(i = 0; i < n; i++) {
    for(j = n-1; j > i; j--) {
      if(A[j-1] > A[j]) {
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	c++;
      }
    }
  }

  for(i = 0; i < n; i++) {
    printf("%d", A[i]);
    if(i != n-1) {
      printf(" ");
    }
  }
  printf("\n%d\n", c);

  return 0;
}
