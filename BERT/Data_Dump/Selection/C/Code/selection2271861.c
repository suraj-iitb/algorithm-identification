#include <stdio.h>
int main() {
  int N, i, j, count=0, kawari, minj, hantei=0;
  scanf("%d", &N);
  int A[N];
  for(i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  for(i = 0; i < N-1; i++) {
    hantei=0;
    minj = i;
    for(j = i; j <= N-1; j++) {
      if(A[j] < A[minj]) {
	minj = j;
	hantei = 1;
      }
    }
    if(hantei == 1) {
      kawari = A[i];
      A[i] = A[minj];
      A[minj] = kawari;
      count++;
    }
  }
  
  for(i = 0; i < N; i++) {
    if(i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", count);
  return 0;
}
