#include <stdio.h>

int a[2000001];
int b[2000001];

void Counting_sort(int x[], int y[], int k, int n) {
  int c[10001];
  for (int i = 0; i <= k; i++)
    c[i] = 0;

  for (int j = 1; j <= n; j++)
    c[x[j]]++;

  for (int i = 1; i <= k; i++)
    c[i] = c[i] + c[i - 1];

  for (int j = n; j >= 1; j--) {
    y[c[x[j]]] = x[j];
    c[x[j]]--;
    }
}

int main(void) {
  int n;
  int max = 0;

  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (max < a[i])
      max = a[i];
  }

  Counting_sort(a, b, max, n);
  
  for (int i = 1; i <= n; i++) {
    printf("%d", b[i]);
    if (i != n)
      printf(" ");
  }
  printf("\n");
  return 0;
}

