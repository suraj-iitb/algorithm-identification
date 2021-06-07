#include <stdio.h>
#define MAX_N 10001

int main() {
  int n, q, S[MAX_N], t, num;
  int i;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    scanf("%d", &S[i]);
  }
  num = 0;
  scanf("%d", &q);
  while(q--) {
    scanf("%d", &t);
    for(i = 0; i < n; ++i) {
      if(S[i] == t) {
        ++num;
        break;
      }
    }
  }
  printf("%d\n", num);
  return 0;
}
