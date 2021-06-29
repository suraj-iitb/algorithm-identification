#include <stdio.h>

int main() {
  int N, A[101], tmp, ans = 0;
  int i, j;
  scanf("%d", &N);
  for(i = 0; i < N; i++) scanf("%d", A+i);
  for(i = 0; i < N-1; i++){
    for(j = N-1; j > i; j--) {
      if(A[j] < A[j-1]) {
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	ans++;
      }
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
