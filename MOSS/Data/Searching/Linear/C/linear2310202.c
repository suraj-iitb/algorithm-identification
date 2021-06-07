#include <stdio.h>
#define NOT_FOUND -1
int A[10000];
int main() {
  int i, j, n, m, l, count=0;
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  scanf("%d", &m);
  int B[m];
  for(i = 0; i < m; i++) {
    scanf("%d", &B[i]);
    l = linearSearch(n, B[i]);
    if(l != NOT_FOUND) count++;
  }
  printf("%d\n", count);
  return 0;
}

int linearSearch(int n, int key) {
  int i=0;
  A[n] = key;
  while(A[i] != key) {
    i++;
  }
  if(i == n) {
    return NOT_FOUND;
  }
  return i;
}
