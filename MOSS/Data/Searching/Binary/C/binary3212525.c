#include <stdio.h>

int main(void) {
  int i, j, k, s[1000000], t[1000000], n, l1, l2, count = 0, left, right, mid;
  char buf[2];
  scanf("%d", &l1);
  for (n = 0; n < l1 && (j = scanf("%d%1[\n]", s+n, buf)) == 1; n++) ;
  if (j == 2)
  n++;
  scanf("%d", &l2);
  for (n = 0; n < l2 && (j = scanf("%d%1[\n]", t+n, buf)) == 1; n++) ;
  if (j == 2)
  n++;

  for (i = 0; i < l2; i++) {
    left = 0;
    right = l1;
    while (left < right) {
      mid = (left + right) / 2;
      if (s[mid] == t[i]) {
        count++;
        break;
      } else if (t[i] < s[mid] ) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
  }

  printf("%d\n", count);
  return 0;
}

