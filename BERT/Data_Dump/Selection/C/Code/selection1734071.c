#include <stdio.h>
int main()
{
  int i, j, minj, tmp, n, count, check;
  int A[100];

  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%d", &A[i]);
  }

  count = 0;
  check = 0;

  for(i=0; i<n; i++) {
    minj = i;
    for(j=i; j<n; j++) {
      if(A[j] < A[minj]) {
	minj = j;
	check = 1;
      }
    }
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    if(check == 1) {
      count++;
      check = 0;
    }
  }

  for(i=0 ; ; i++) {
    printf("%d", A[i]);
    if(i == n-1) break;
    printf(" ");
  }
  printf("\n%d\n", count);

  return 0;
}
