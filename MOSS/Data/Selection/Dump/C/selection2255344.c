#include <stdio.h>

int main() {
  int N, A[101], mni, tmp, ans = 0;
  int i, j;
  scanf("%d", &N);
  for(i = 0; i < N; i++) scanf("%d", A+i);
  for(i = 0; i < N; i++) {
    mni = i;
    for(j = i; j < N; j++) {
      if(A[j] < A[mni]) mni = j;
    }
    if(mni != i) {
      ans++;
      tmp = A[i];
      A[i] = A[mni];
      A[mni] = tmp;
    }
  }
  for(i = 0; i < N; i++) {
    if(i) printf(" ");
    printf("%d", A[i]);
  }
  puts("");
  printf("%d\n", ans);
  return 0;
}
