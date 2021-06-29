#include <stdio.h>

int main(void){
  int n, s[10000], q, t[500], c;
  int i, j;

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
    for (j = 0; j < n; j++) {
      if (t[i] == s[j]) {
        c++;
        break;
      }
    }
  }

  printf("%d\n", c);

  return 0;
}
