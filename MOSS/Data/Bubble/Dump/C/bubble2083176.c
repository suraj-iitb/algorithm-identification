#include <stdio.h>

int main()
{
  int n, i, j, flag = 1, temp, cnt = 0;
  int a[100];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  i = 0;
  while (flag) {
    flag = 0;
    for (j = n - 1; j > i; j--) {
      if (a[j] < a[j - 1]) {
        temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
        cnt++;
        flag = 1;
      }
    }
    i++;
  }

  for (i = 0; i < n; i++) {
    if (i == 0) {
      printf("%d", a[i]);
    } else {
      printf(" %d", a[i]);
    }
  }
  puts("");
  printf("%d\n", cnt);

  return 0;
}
