#include <stdio.h>

int main(){
  int A[100], i, j, N, temp;
  int count = 0;
  int flag = 1;
  scanf("%d", &N);
  for(i = 0; i < N; i++) scanf("%d", &A[i]);
  i = 0;
  while(flag){
    flag = 0;
    for(j = N-1; i+1 <= j; j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag = 1;
	count++;
      }
    }
    i++;
  }
  printf("%d", A[0]);
  for(i = 1; i < N; i++) printf(" %d", A[i]);
  printf("\n");
  printf("%d\n", count);

  return 0;
}

