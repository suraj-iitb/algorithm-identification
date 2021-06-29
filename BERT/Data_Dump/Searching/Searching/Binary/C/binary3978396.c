#include <stdio.h>

int s[100005], n;

int binarySearch(int key) {
  int left = 0;
  int right = n;

  while (left < right) {
    int mid = left + (right-left) / 2;
    if (key == s[mid]) return 1;
    else if (key > s[mid]) { left = mid + 1; }
    else { right = mid; }
  }
  return 0;
}

int main() {
  int q, i;
  int t, ans = 0;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);

  for (i = 0; i < q; i++) {
    scanf("%d", &t);
    if (binarySearch(t)) {
      ans++;
    }
  }

  printf("%d\n", ans);

  return 0;
}

