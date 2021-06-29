#include <stdio.h>

int hasValue(int, int);

int S[10000];
int T[500];

int main() {
  int n, q, i, num, cnt = 0;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &num);
    if (hasValue(n, num)) cnt++;
  }

  printf("%d\n", cnt);

  return 0;
}

int hasValue(int n, int num) {
  int i;
  for (i = 0; i < n; i++) {
    if (S[i] == num) return 1;
  }
  return 0;
}
