#include<stdio.h>

void bubbleSort(int a[], int n) {
  int flag, i, tmp, count;
  flag = 1;

  count = 0;
  while (flag) {
    flag = 0;
    for ( i = n-1; i > 0; i-- ) {
      if ( a[i] < a[i-1] ) {
        tmp = a[i-1];
        a[i-1] = a[i];
        a[i] = tmp;
        count++;
        flag = 1;
      }
    }
  }

  for ( i = 0; i < n; i++ ) {
    printf("%d", a[i]);
    if ( i != n-1 ) printf(" ");
  }

  printf("\n%d\n", count);
}

int main() {
  int n, i, a[100];

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);

  bubbleSort(a, n);

  return 0;
}

