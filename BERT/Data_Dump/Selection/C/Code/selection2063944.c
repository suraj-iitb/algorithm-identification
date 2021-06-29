#include<stdio.h>

int main(){
  int A[100], tmp, N, i, j, minj, cnt=0;
  
  scanf("%d", &N);
  for (i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }
  
  for (i=0; i<N; i++) {
    minj = i;
    for (j=i; j<N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    if (minj != i) {
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      cnt++;
    }
  }

  printf("%d", A[0]);
  for (i=1; i<N; i++) {
    printf(" %d", A[i]);
  }
  printf("\n%d\n", cnt);
  return 0;
}
