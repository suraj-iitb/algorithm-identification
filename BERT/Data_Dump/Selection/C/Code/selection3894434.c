#include <stdio.h>

#define N_MAX 100

int count = 0;

void
selection_sort(int *a, int n)
{
  int i, j, minj, v;

  for (i = 0; i < n; i++) {
    minj = i;
    for (j = i + 1; j < n; j++)
      if (a[j] < a[minj])
        minj = j;
    if (i != minj) {
      count++;
      v = a[i];
      a[i] = a[minj];
      a[minj] = v;
    }
  }
}

int
main(void)
{
  int i, n;
  int a[N_MAX];

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", a + i);

  selection_sort(a, n);
  for (i = 0; i < n; i++)
    printf("%s%d", i ? " " : "", a[i]);
  printf("\n%d\n", count);

  return 0;
}


