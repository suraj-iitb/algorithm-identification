#include <stdio.h>

int binary (int S[], int key, int n) {
  int mid, left = 0, right = n, f = 0;
  while (left < right) {
        mid = (left + right) / 2;
        if (S[mid] == key) {
            f = 1;
            break;
        }
        else if (key < S[mid]) {
            right = mid;
        }
        else if (key > S[mid]) {
            left = mid + 1;
        }
  }
  return f;
}

int main (void) {
  int S[100000], n, q, i, key, cnt = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for (i = 0; i < q; ++i) {
    scanf("%d", &key);
    if (binary (S, key, n)) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}

