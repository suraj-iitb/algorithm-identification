#include<stdio.h>

int main(){
  int A[100], tmp, N, i, j;
  int cnt = 0;
  
  scanf("%d", &N);
  for (i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }

  for (i=0; i<N-1; i++) {    
    for (j=0; j<N-i-1; j++) {
      if (A[j] > A[j+1]) {
        tmp = A[j];
        A[j] = A[j+1];
        A[j+1] = tmp;
        cnt++;
      }
    }
  }

  for (j=0; j<N-1; j++) {
    printf("%d ", A[j]);
  }
  printf("%d\n%d\n", A[N-1], cnt);
  return 0;
}
