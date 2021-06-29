#include <stdio.h>

int main(void)
{
  int i, j, n, a[1000], v, k;
  scanf("%d", &n);
  for (i = 0; i < n; i++)  {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n; i++)  {
    v = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > v)  {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    for (k = 0; k < n - 1; k++)  {
      printf("%d ", a[k]);
    }
    printf("%d\n", a[n - 1]);
  }

  return 0;
}
