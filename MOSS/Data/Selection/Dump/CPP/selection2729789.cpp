#include <stdio.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repi(i, n, a) for(int i = a; i < n; ++i)

int main(void) {
  int n, i, j, ans = 0;
  scanf("%d", &n);
  int a[n];
  rep(i, n) scanf("%d", &a[i]);
  int flag = 1;
  rep(i, n) {
    int minj = i, t;
    repi(j, n, i) if(a[j] < a[minj]) minj = j;
    t = a[i], a[i] = a[minj], a[minj] = t;
    if(i != minj) ++ans;
  }
  rep(i, n) {
    if(i) printf(" %d", a[i]);
    else printf("%d", a[i]);
  }
  printf("\n%d\n", ans);
  return 0;
}
