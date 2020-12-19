#include <stdio.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repi(i, n) for(int i = 1; i < n; ++i)

int main(void) {
  int n, i, j;
  scanf("%d", &n);
  int a[n];
  rep(i, n)scanf("%d", &a[i]);
  repi(i, n) {
    rep(j, n) {
      if(j) printf(" %d", a[j]);
      else printf("%d", a[j]);
    }
    printf("\n");
    int v = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      --j;
    }
    a[j + 1] = v;
  }
  rep(j, n) {
    if(j) printf(" %d", a[j]);
    else printf("%d", a[j]);
  }
    printf("\n");
  return 0;
}
