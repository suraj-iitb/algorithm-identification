#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>
#define ll long long
#define PI acos(-1)

int selectionSort(int a[], int n) {
  int count = 0, tmp, flag;
  for (int i = 0; i < n; i++) {
    flag = 0;
    int minj = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[minj]) {
        minj = j;
        flag = 1;
      }
    }
    if (flag) count++;
    tmp = a[i]; a[i] = a[minj]; a[minj] = tmp;
  }
  return count;
}

int main () {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  int count = selectionSort(a, n);

  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
  printf("%d\n", count);
  return 0;
}
