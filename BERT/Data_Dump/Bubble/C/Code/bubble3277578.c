#include <stdio.h>
#include <stdlib.h>
int main() {
  int N,j, *A,flag = 1,dummy,count = 0;

  scanf("%d",&N);
  A = (int *)malloc(N * sizeof(int));
  for(j = 0;j < N;j++) {
    scanf("%d",&A[j]);
  }
  while(flag) {
    flag = 0;
    for(j = N - 1;j != 0;j--){
      if(A[j] < A[j - 1]){
	dummy = A[j];
	A[j] = A[j - 1];
	A[j - 1] = dummy;
	flag = 1;
	count++;
      }
    }
  }
  for(j = 0;j < N;j++){
    printf("%d",A[j]);
    if(j != N - 1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}
