#include <stdio.h>
int main()
{
  int i, flag, n, tmp, count = 0;
  int A[100];

  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%d", &A[i]);
  }

  flag = 1;
  while(flag) {
    flag = 0;
    for(i=n-1; i>=1; i--) {
      if(A[i] < A[i-1]) {
	tmp = A[i];
	A[i] = A[i-1];
	A[i-1] = tmp;
	flag = 1;
	count++;
      }
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
