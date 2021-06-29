#include <stdio.h>
#include <stdlib.h>

void trace (int a[], int n) {
  int i;
  
  for (i = 0; i < n; i++) {
    if (i >= 1) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
  
}

int main () {
  int *a, i, j, k, n, key;
  
  scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * n);
  
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  
  trace(a, n);
    
  for (i = 1; i < n; i++) {
    key = a[i];
    j = i - 1;
    
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    
    a[j + 1] = key;
    
    trace(a, n);
  }
  
  free(a);
  
  return 0;
}
