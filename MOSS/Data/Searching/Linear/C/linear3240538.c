#include <stdio.h>

int search(int a[], int n, int key) {
  int i = 0;
  a[n] = key;

  while (a[i] != key) i++;

  return i != n;
}

int main() {
  int i;
  int count = 0;
  int key;
  int n, q;
  scanf("%d", &n);
  int a[n];
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &key);
    if (search(a, n, key)) ++count;
  }

  printf("%d\n",count);

  return 0;
}

