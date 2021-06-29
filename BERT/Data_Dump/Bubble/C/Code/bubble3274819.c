#include<stdio.h>

int main(){
  int N, i, j, A[100], temp, flag = 1, count = 0;

  scanf("%d", &N);

  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }

  while(flag){
    flag = 0;
    for(j = N-1; j >= 1 ; j--){
      if(A[j] < A[j-1]){
	temp = A[j-1];
	A[j-1] = A[j];
	A[j] = temp;
	flag = 1;
	count++;
      }
    }
  }

  for(i = 0; i < N; i++){
    if(i == N-1){
      printf("%d\n",A[i]);
      break;
    }
    printf("%d ", A[i]);
  }
  printf("%d\n", count);
}

