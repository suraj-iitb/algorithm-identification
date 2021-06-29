#include <stdio.h>

int linarSearch(int *A, int n, int key ) {
  int i = 0;
  
  A[n] = key;
  while(A[i] != key) {
    i++;
  }
  if(i == n) return 0;
  return 1;
  
}

int main () {
  int i, n, q, S[10000], T[500], m = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d", &T[i]);

  for(i = 0; i < q; i++) {
    m += linarSearch(S, n, T[i]);
  }

  printf("%d\n", m);
  return 0;
}
