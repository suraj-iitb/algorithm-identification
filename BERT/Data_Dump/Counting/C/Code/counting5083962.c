#include <stdio.h>
#include <stdlib.h>
#define K 10000

void CountingSort(int*,int*,int);

int main() {
  int *a, *b, n, i;

  scanf("%d", &n);
  a = (int*)malloc(sizeof(int)*n+1);
  b = (int*)malloc(sizeof(int)*n+1);
  for(i=1;i<=n;i++) scanf("%d", &a[i]);

  CountingSort(a,b,n);
  for(i=1;i<n;i++) printf("%d ", b[i]);
  printf("%d\n", b[i]);
  
  free(a);
  free(b);
  return 0;
}

void CountingSort(int *a, int *b, int n) {
  int c[K+1], i;

  for(i=0;i<=K;i++) c[i] = 0;
  for(i=1;i<=n;i++) c[a[i]]++;
  for(i=1;i<=K;i++) c[i] += c[i-1];
  for(i=n;i>=1;i--) {
    b[c[a[i]]] = a[i];
    c[a[i]]--;
  }
  return;
}

