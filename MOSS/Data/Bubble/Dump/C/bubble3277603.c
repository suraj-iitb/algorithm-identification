#include<stdio.h>

int main(){
  int i, j, temp, flag, N, A[100], count = 0;
  scanf("%d", &N);
  if(N >= 1 && N <= 100){
    for(j = 0; j < N; j++)
      scanf("%d", &A[j]);
    i = 0;
    flag = 1;
    while(flag){
      flag = 0;
      for(j = N - 1; j > i; j--){
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
    for(j = 0; j < N; j++){
      if(j != N-1) printf("%d ", A[j]);
      else printf("%d\n", A[j]);
    }
    printf("%d\n", count);
  }
  return 0;
}

