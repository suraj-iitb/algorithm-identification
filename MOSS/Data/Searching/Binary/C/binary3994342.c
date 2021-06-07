#include <stdio.h>

int a[1000000], n;

int binary_search(int key) {
  int left = 0;
  int right = n;
  int mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (key == a[mid]) return 1;
    if (key > a[mid]) left = mid + 1;
    else if (key < a[mid]) right = mid;
  }

  return 0;
}

int main() {
  int i, q, k, sum = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &k);
    if (binary_search(k)) sum++;
  }
  printf("%d\n", sum);
  return 0;
}
