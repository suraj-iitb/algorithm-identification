#include<stdio.h>
int main() {
  int i=0, j, flag=1, kawari, N, count=0;
  scanf("%d", &N);
  int A[N];
  for(i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  i = 0;
  while(flag == 1) {
    flag=0;
    for(j = N-1; j >= i+1; j--) {
      if(A[j] < A[j-1]) {
	kawari = A[j];
	A[j] = A[j-1];
	A[j-1] = kawari;
	flag = 1;
	count++;
      }
    }
    i++;
  }
  
  for(j = 0; j < N; j++) {
    if(j > 0) printf(" ");
    printf("%d", A[j]);
  }
  printf("\n%d\n", count);
  return 0;
}
