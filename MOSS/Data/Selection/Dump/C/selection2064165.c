#include <stdio.h>

int main(void)
{
  int i, j, minj, temp, n, a[100], k = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++)  {
    scanf("%d", &a[i]);
  }

  for (i = 0; i < n - 1; i++)  {
    minj = i;
    for (j = i + 1; j < n; j++)  {
      if (a[j] < a[minj])  {
        minj = j;
      }
    }
    if (minj != i)  {
      k++;
      temp = a[i];
      a[i] = a[minj];
      a[minj] = temp;
    }
  }

  for (i = 0; i < n - 1; i++) {
    printf("%d ", a[i]);
  }

  printf("%d\n%d\n", a[n - 1], k);

  return 0;
}
