#include <stdio.h>
#define N  100

void trace(int a[], int n) {
  int i;
  printf("%d", a[0]);
  for (i = 1; i < n; i++)
    printf(" %d", a[i]);
  putchar('\n');
}

void insertionSort(int a[], int n) {
  int t, i, j, k;
  
  for (i = 1; i < n; i++) {
    t = a[i];
    j = i - 1;
    
    while (j >= 0 && a[j] > t) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = t;
    trace(a, n);
  }
}

int main(void) {
  int a[N], n, i, j;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  trace(a, n);
  
  insertionSort(a, n);
    
  return 0;
}

