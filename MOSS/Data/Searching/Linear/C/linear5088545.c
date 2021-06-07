#include <stdio.h>

int main() {
  int n, m;
  int A[10000], B[500];
  int i, j, k;
  int cnt = 0;

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
	cnt++;
	break;
      }
    }
  }

  printf("%d\n", cnt);

  return 0;
}

