#include <stdio.h>
#define MAX 10001
#define NOT_FOUND -1

int linearSearch(int *A, int N, int key) {
  int i = 0;
  
  A[N] = key;
  while(A[i] != key) {
    i++;
  }
  if(i == N) return NOT_FOUND;
  return i;
}

int main() {
  int n, q, s[MAX], t, i, count = 0;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  
  scanf("%d", &q);
  for(i = 0; i < q; i++) {
    scanf("%d", &t);
    if(linearSearch(s, n, t) >= 0) count++;
  }
  
  printf("%d\n", count);
  return 0;
}

