#include <stdio.h>

void print_a(int a[],int n) {
  int i;

  for (i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i < n - 1)
      printf(" ");
  }
  printf("\n");
}

void insertion_sort(int a[],int n) {
  int i, j;
  int num;
  
  for (i = 1; i < n; i++) {
    print_a(a, n);
    j = i;
    num = a[i];
    while(j > 0 && num < a[j - 1]) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = num;
  }
}

int main(void) {
  int n;
  int a[1000];
  int i;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  
  insertion_sort(a, n);

  print_a(a, n);
  
  return 0;
}

