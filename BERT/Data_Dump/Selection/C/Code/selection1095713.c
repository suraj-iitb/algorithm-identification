#include<stdio.h>
#include<stdlib.h>

int main() {
  int n, i, j;
  int c = 0;
  int temp, min;
  int *A;

  scanf("%d", &n);
  A = malloc(n*sizeof(int));
  for(i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  for(i = 0; i < n; i++) {
    min = i;
    for(j = i; j < n; j++) {
      if(A[j] < A[min]) {
	min = j;
      }
    }
    if(min != i) {
	temp = A[i];
	A[i] = A[min];
	A[min] = temp;
	c++;
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
