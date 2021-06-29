#include <stdio.h>

static const int N = 100;

void trace(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i != 0) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
}

int main() {
  int n;
  int a[N];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  trace(a, n);
  
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 & a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
    trace(a, n);
  }
  return 0;
}
