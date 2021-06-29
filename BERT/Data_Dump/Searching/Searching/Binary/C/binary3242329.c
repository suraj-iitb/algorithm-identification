#include <stdio.h>

int search(int a[], int key, int n) {
  int start, fin, current;
  fin = n;
  start = 0;

  while (fin > start) {
    current = (fin + start) / 2;
    if (a[current] == key) {
      return 1;
    } else if (a[current] < key) {
      start = current + 1;
    } else {
      fin = current;
    }
  }

  return 0;
}


int main() {
  int key;
  int n, q;
  int sum = 0;
  int i;
  scanf("%d", &n);
  int s[n];
  for (i = 0; i < n; i++)
    scanf("%d", &s[i]);
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &key);
    if (search(s, key, n))  ++sum;
  }

  printf("%d\n", sum);

  return 0;
}

