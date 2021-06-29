#include <stdio.h>
int main() {

  int A[100],minj,i,j,x,N,count=0,flag;

  scanf("%d",&N);
  for(i = 0; i < N; i++) {
    scanf("%d",&A[i]);
  }

  for(i = 0; i < N; i++) {
    minj = i;
    flag = 0;
    for(j = i; j < N; j++) {
      if(A[j] < A[minj]) {
    minj = j;
    flag = 1;

      }
    }
    if(flag == 1) {
      x = A[i];
      A[i] = A[minj];
      A[minj] = x;
      count++; 
    }
  }

  for(i = 0; i < N; i++) {
    printf("%d",A[i]);
    if(N-1 != i) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

