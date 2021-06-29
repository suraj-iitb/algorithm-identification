#include <stdio.h>

void insertionSort(int as[], int n)
{
  int i, j, k;
  int key;

  for (i = 0; i < n; i++) {
    key = as[i];
    j = i - 1;
    while (j >= 0 && as[j] > key) {
      as[j + 1] = as[j];
      j--;
    }
    as[j + 1] = key;
    for (k = 0; k < (n - 1); k++) {
      printf("%d ", as[k]);
    }
    printf("%d\n", as[n - 1]);
  }
}

int main(int argc, char *argv[])
{
  char row[4];
  int n = atoi(fgets(row, sizeof(row), stdin));
  int as[n];
  int i;

  for (i = 0; i < n; i++) {
    scanf("%d", &as[i]);
  }

  insertionSort(as, n);

  return 0;
}
