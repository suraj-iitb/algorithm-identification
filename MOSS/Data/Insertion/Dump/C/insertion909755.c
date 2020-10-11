#include <stdio.h>

int main(void) {
  int i, j, key, n, array[100];

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  for (i = 0; i < n; i++) {
    key = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;

    for (j = 0; j < n; j++) {
      printf("%d%c", array[j], j == n - 1 ? '\n' : ' ');
    }
  }

  return 0;
}
