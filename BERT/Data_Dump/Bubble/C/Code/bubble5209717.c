#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>
#define ll long long
#define PI acos(-1)



int main () {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  int count = 0, tmp;
  for (int i = 0; i < n-1; i++) {
    for (int j = n-1; j > i; j--) {
      if (a[j-1] > a[j]) {
        tmp = a[j]; a[j] = a[j-1]; a[j-1] = tmp;
        count++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (i > 0) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
  printf("%d\n", count);

  return 0;
}
