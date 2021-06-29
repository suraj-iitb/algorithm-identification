#include <stdio.h>

int main(void){
  int n, s[100000], q, t[50000], c;
  int left, right, mid, key;
  int i;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &t[i]);
  }

  c = 0;

  for (i = 0; i < q; i++) {
    key = t[i];
    left = 0;
    right = n;
    while (left < right) {
      mid = (left + right) / 2;
      if (s[mid] == key) {
        c++;
        break;
      }
      else if (key < s[mid]) {
        right = mid;
      }
      else {
        left = mid + 1;
      }
    }
  }

  printf("%d\n", c);

  return 0;
}
