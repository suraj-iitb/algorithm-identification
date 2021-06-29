#include <cstdio>

void insertionSort(int a[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
    printf("%d ", a[i]);
  printf("%d\n", a[i]);
  for (i = 1; i <= n - 1; i++) {
    int v = a[i];
    for (j = i - 1; a[j] > v && j >= 0; j--) 
      a[j + 1] = a[j];
    a[j + 1] = v;
    for (j = 0; j < n - 1; j++)
      printf("%d ", a[j]);
    printf("%d\n", a[j]);
  }
}

int main(void)
{
  int n;
  int a[100];
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  insertionSort(a, n);

  return 0;
}

