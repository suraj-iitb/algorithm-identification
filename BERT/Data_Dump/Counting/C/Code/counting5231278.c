#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>
#define ll long long
#define PI acos(-1)
#define Max 2000001
#define Vmax 10001


int main () {
  unsigned short *a, *b;
  int n;
  scanf("%d", &n);

  int c[Vmax];
  for (int i = 0; i < Vmax; i++) c[i] = 0;

  a = malloc(sizeof(short) * n + 1);
  b = malloc(sizeof(short) * n + 1);

  for (int i = 0; i < n; i++) {
    scanf("%hu", &a[i+1]);
    c[a[i+1]]++;
  }

  for (int i = 0; i < Vmax; i++) {
    c[i+1] = c[i+1] + c[i];
  }

  for (int j = 1; j < n+1; j++) {
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }

  for (int i = 1; i <= n; i++) {
    if (i > 1) printf(" ");
    printf("%d", b[i]);
  }
  printf("\n");
  return 0;
}
