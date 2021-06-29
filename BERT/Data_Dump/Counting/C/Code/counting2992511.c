// counting sort
#include <stdio.h>
#include <stdlib.h>

void CountingSort(int* , int* , int, int);


int main() {
  int i, n, k;
  int *a, *b;
  int max;
  
  // input
  scanf("%d", &n);
  a = (int *)malloc(n * sizeof(int));
  b = (int *)malloc(n * sizeof(int));
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  // search max
  max = a[0];
  for(i = 1; i < n; i++) {
    if(max < a[i]) max = a[i];
  }
  k = max;

  // sort
  CountingSort(a, b, k, n);

  for(i = 0; i < n; i++) {
    printf("%d", b[i]);
    if(i != n - 1) printf(" ");
  }
  printf("\n");
  
  return 0;
}

void CountingSort(int *a, int *b, int k, int n) {
  int i, j;
  int *c;

  // create an array : c
  c = (int *)malloc((k+1) * sizeof(int));
  // initialization
  for(i = 0; i <= k; i++) {
    c[i] = 0;
  }
  for(j = 0; j < n; j++) {
    c[a[j]] = c[a[j]] + 1;
  }
  for(i = 1; i <= k; i++) {
    c[i] = c[i] + c[i - 1];
  }
  for(j = n - 1; j >= 0; j--) {
    b[c[a[j]] - 1] = a[j];
    c[a[j]] = c[a[j]] - 1;
  }
}

