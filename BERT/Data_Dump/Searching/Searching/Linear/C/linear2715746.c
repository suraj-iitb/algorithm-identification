#include <stdio.h>

int main() {
  int n, m;
  int A[10000], B[500];
  int i, j;
  int count = 0;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d", &B[i]);
  }

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (A[j] == B[i]) {
	count++;
	break;
      }
    }
  }

  printf("%d\n", count);
  
  return 0;
}
