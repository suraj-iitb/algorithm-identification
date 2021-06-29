/* Bubble Sort */

#include <stdio.h>

int main(void) {
  int n, swap = 0, i, j, tmp;
  scanf("%d", &n);
  int a[n];
  for(i = 0; i < n; i++) scanf("%d", &a[i]);
  for(i = 0; i < n; i++)
    for(j = n - 1; j > i; j--)
      if (a[j] < a[j - 1]) {
        tmp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = tmp;
        swap++;
      }
  for(i = 0; i < n; i++) {
    printf("%d", a[i]);
    if(i < n - 1) printf(" ");
  }
  printf("\n%d\n", swap);

  return 0;
}
