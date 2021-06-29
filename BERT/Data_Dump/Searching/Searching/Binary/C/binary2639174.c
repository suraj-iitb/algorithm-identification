#include <stdio.h>

int main(void) {
  int n, q, i, key, flag = 0, count = 0;
  int left, mid, right;
  scanf("%d", &n);
  int S[n];
  for(i = 0; i < n; i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  int T[q];
  for(i = 0; i < q; i ++) scanf("%d", &T[i]);

  for(i = 0; i < q; i ++) {
    key = T[i];
    left = 0;
    right = n;
    while(left < right) {
      mid = (left + right) / 2;
      if(S[mid] == key) {
        count ++;
        break;
      }
      else if(key < S[mid]) {right = mid;}
      else {left = mid + 1;}
    }
  }

  printf("%d\n", count);
  return 0;

}
