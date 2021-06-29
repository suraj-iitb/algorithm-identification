#include <stdio.h>
int main() {
  int N, A[101], v;
  int i, j;
  scanf("%d", &N);
  for(i = 0; i < N; i++) scanf("%d", A+i);
  for(i = 1; i <= N; i++) {
    for(j = 0; j < N; j++) {
      if(j) printf(" ");
      printf("%d", A[j]);
    }
    puts("");
    if(i == N) break;
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }
  return 0;
}
