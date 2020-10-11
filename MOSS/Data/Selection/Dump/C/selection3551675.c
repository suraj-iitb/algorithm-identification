#include <stdio.h>

int count = 0;

void selection_sort(int a[], int n) {
  int minj;
  int b;
  for (int i = 0; i < n - 1; i++) {
    minj = i;
    for (int j = i + 1; j < n; j++)
      if (a[j] < a[minj]) 
	minj = j;
    if (i != minj) {
      b = a[i];
      a[i] = a[minj];
      a[minj] = b;
      count++;
    }
  }
}

int main(void) {
  int n;
  int a[100];

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  selection_sort(a, n);

  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n");
  printf("%d\n", count);
  
  return 0;
}

