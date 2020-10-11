#include <stdio.h>

int SelectionSort(int n, int num[]) {
  int i, j;
  int min;
  int count = 0;

  for (i = 0; i < n-1; i++) {
    min = i;
    for (j = i+1; j < n; j++) {
      if (num[j] < num[min]) {
	min = j;
      }
    }
    if (min != i) {
      int tmp;
      tmp = num[i];
      num[i] = num[min];
      num[min] = tmp;
      count++;
    }
  }

  return count;
}

int main() {
  int n;
  int num[100];
  int i;
  int cnt;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &num[i]);
  }

  cnt = SelectionSort(n, num);

  for (i = 0; i < n; i++) {
    printf("%d", num[i]);
    if (i == n-1) break;
    putchar(' ');
  }
  putchar('\n');
  printf("%d\n", cnt);

  return 0;
}

