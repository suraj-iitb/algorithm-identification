/* Selection Sort */

#include <stdio.h>

int main(void) {
  int i, j, swap = 0, n, tmp, mini;
  scanf("%d", &n);
  int a[n];
  for(i = 0; i < n; i++) scanf("%d", &a[i]);
  for(i = 0; i < n; i++) {
    mini = i;
    for(j = i; j < n; j++)
      if(a[j] < a[mini])
        mini = j;
    if(i != mini) swap++;
    tmp = a[i];
    a[i] = a[mini];
    a[mini] = tmp;
  }

  for(i = 0; i < n; i++) {
    printf("%d", a[i]);
    if(i < n - 1) printf(" ");
  }
  printf("\n%d\n", swap);

  return 0;
}
