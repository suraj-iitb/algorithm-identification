#include <stdio.h>

int n;
int a[100];
int count = 0;

int selectionsort(void) {
  for (int i = 0; i <= n - 1; i++) {
    int mini = i;
    for (int j = i; j <= n - 1; j++) {
      if (a[j] < a[mini]) {
        mini = j;
      }
    }
    if (mini != i) {
      int temp = a[i];
      a[i] = a[mini];
      a[mini] = temp;
      count++;
    }
  }
  return 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  selectionsort();

  for (int i = 0; i < n - 1; i++) {
    printf("%d ", a[i]);
  }
  printf("%d\n", a[n - 1]);

  printf("%d\n", count);

  return 0;
}
