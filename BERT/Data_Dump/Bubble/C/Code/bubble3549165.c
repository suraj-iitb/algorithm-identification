#include <stdio.h>

int count = 0;

void bubble_sort(int a[], int n) {
  int flag = 1;
  int b;

  while (flag == 1) {
    flag = 0;
    for (int i = n - 1; i >= 1; i--) 
      if (a[i] < a[i - 1]) {
	b = a[i];
	a[i] = a[i - 1];
	a[i - 1] = b;
	count++;
	flag = 1;
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

  bubble_sort(a, n);

  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i != n - 1)
      printf(" ");
    else if (i == n - 1)
      printf("\n");
  }
  printf("%d\n", count);
  
  return 0;
}

