#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>
#define ll long long
#define PI acos(-1)
#define ichi 1000000007

int isOk(int index, int key, int a[]) {
  if (a[index] == key) return 0;
  else if (a[index] > key) return 1;
  else return -1;
}
int binary_serch(int key, int left, int right, int a[]) {
  int fl = 0;
  while (right - left > 1) {
    int middle = left + (right - left) / 2;
    if (isOk(middle, key, a) == 1) right = middle;
    else if (isOk(middle, key, a) == -1) left = middle;
    else {
      fl = 1;
      break;
    }
  }
  if (fl) return 1;
  else return 0;
}
  
int main () {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int q;
  scanf("%d", &q);
  int b[n];
  for (int i = 0; i < q; i++) scanf("%d", &b[i]);

  int ans = 0;
  for (int i = 0; i < q; i++) {
    if (binary_serch(b[i], -1, n, a)) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
