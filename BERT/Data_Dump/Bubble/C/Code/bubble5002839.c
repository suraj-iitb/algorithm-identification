#include <stdio.h>

int n;
int a[100];
int count = 0;
int i = 0;
int swapped = 1;

int bubblesort(void) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        count++;
      }
    }
  }
  return 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  bubblesort();

  for (int i = 0; i < n - 1; i++) {
    printf("%d ", a[i]);
  }
  printf("%d", a[n - 1]);
  printf("\n%d\n", count);

  return 0;
}
