#include <stdio.h>
#define  N 100

int bubbleSort(int *B, int n) {
  int i, j, tmp, count = 0;
  
  for(i = 0; i < n; i++) {
    for (j = n-1; j > i; j--) {
      if(B[j] < B[j-1]) {
	tmp = B[j];
	B[j] = B[j-1];
	B[j-1] = tmp;
	count++;
      }
    }
  }
  return count;
}

int main() {
  int i, A[N], n, cnt;
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  cnt = bubbleSort(A, n);
  
  for(i = 0; i < n; i++) {
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", cnt);
  
  return 0;
}
