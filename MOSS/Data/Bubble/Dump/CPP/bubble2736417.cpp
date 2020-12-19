#include <stdio.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repi(i, n, a) for(int i = a; i < n; ++i)

int main(void) {
  int n, i, j, ans = 0;
  scanf("%d", &n);
  int a[n];
  rep(i, n) scanf("%d", &a[i]);
  int flag = 1;
  while(flag) {
    flag = 0;
    for(j = n - 1; j > 0; --j) {
      if(a[j] < a[j - 1]) {
        int t;
        t = a[j], a[j] = a[j - 1], a[j - 1] = t;
        flag = 1;
        ++ans;
       }
    }
  }
  rep(i, n) {
    if(i) printf(" %d", a[i]);
    else printf("%d", a[i]);
  }
  printf("\n%d\n", ans);
  return 0;
}
