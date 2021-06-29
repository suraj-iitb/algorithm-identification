#include<stdio.h>
int main(){
  int n, q, ans = 0;
  int i, j;
  int S[10001], T[500];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }

  for (i = 0; i < q; i++) {
    S[n] = T[i];
    j = 0;
    while (S[j] != T[i]) {
      j++;
    }
    if (j != n) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
