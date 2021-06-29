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
  
  for (int j = 0; j < n; j++) {
      if (j > 0) printf(" ");
      printf("%d", a[j]);
    }
  printf("\n");
  for (int i = 1; i < n; i++) {
    int v = a[i];
    int j = i-1;
    while (j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
      a[j+1] = v;
    }
    for (int j = 0; j < n; j++) {
      printf("%d", a[j]);
      if (j != n-1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
