#include <stdio.h>

int main(void)  {
  int i, j, n, a[100], flag, tmp, k = 0;

  scanf("%d", &n);
  for (i = 0; i < n; i++)  {
    scanf("%d", &a[i]);
  }
  flag = 1;
  while (flag)  {
    flag = 0;
    for (j = n - 1; j >= 1; j--)  {
      if (a[j] < a[j - 1])  {
        tmp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = tmp;
        flag = 1;
        k++;
      }
    }
  }

  for (i = 0; i < n - 1; i++)  {
    printf("%d ", a[i]);
  }

  printf("%d\n%d\n", a[n - 1], k);

  return 0;
}
