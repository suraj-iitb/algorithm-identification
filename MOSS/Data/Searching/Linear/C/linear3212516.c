#include <stdio.h>

int main(void) {
  int i, j, k, s[10000], t[10000], n, l1, l2, key, temp, count = 0;
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
    for (j = 0; j < l1; j++) {
      if (t[i] == s[j]) {
        count++;
        break;
      }
    }
  }

  printf("%d\n", count);
  return 0;
}

