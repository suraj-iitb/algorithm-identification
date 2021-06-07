#include <stdio.h>

int binarySearch(int *A, int n, int key ) {
  int left = 0, right = n, mid;
  
  while (left < right) {
    mid = (left + right) / 2;
    if (key == A[mid]) return 1;
    if (key > A[mid]) left = mid + 1;
    else if(key < A[mid]) right = mid;
  }
  return 0;
}

int main () {
  int i, n, q, S[100000], T[50000], m = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d", &T[i]);

  for(i = 0; i < q; i++) {
    m += binarySearch(S, n, T[i]);
  }

  printf("%d\n", m);
  return 0;
}
