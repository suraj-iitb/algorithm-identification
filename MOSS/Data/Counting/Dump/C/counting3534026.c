#include <stdio.h>
#include <stdlib.h>

void countingsort(int a[], int b[], int k, int n) {
  int i, j;
  int c[k+1];
  for (i = 0; i <= k; i++) 
    c[i] = 0;
  for (i = 0; i < n; i++) 
    c[a[i]]++;
  for (i = 1; i <= k; i++)
    c[i] += c[i-1];
  for (i = n-1; i >= 0; i--) {
    b[c[a[i]]-1] = a[i];
    c[a[i]]--;
  }
}
    
int main(void)
{
  int n, i;
  int *a, *b;
  int max = 0;
  scanf("%d", &n);
  a = malloc(sizeof(int) * n);
  b = malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] > max)
      max = a[i];
  }
  countingsort(a, b, max, n);
  for (i = 0; i < n-1; i++)
    printf("%d ", b[i]);
  printf("%d\n", b[n-1]);
  return 0;
}

