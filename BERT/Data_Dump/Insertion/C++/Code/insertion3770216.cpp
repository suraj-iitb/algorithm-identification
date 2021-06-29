#include<stdio.h>

void trace(int a[], int n) {
  int i;
  for ( i = 0; i < n; i ++) {
    if ( i > 0 ) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
}

void insertSort(int a[], int n) {
  int v, i, j;
  for ( i = 1; i < n; i++ ) {
    v = a[i];
    j = i - 1;
    while ( j >= 0 && a[j] > v ) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    trace(a, n);
  }
}

int main() {
  int n, i, j, a[100];
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);

  trace(a, n);
  insertSort(a, n);

  return 0;
}

