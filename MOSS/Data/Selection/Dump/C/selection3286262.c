#include<stdio.h>

int main(){
  int i, j, minj, N, temp, count = 0, flag = 0, k;
  int A[100];

  scanf("%d", &N);

  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }

  for(i = 0; i < N; i++){
    flag=0;
    minj = i;
    for(j = i; j < N; j++){
      if(A[j] < A[minj]){
	flag=1;
	minj = j;
      }
    }
    if(flag==1){
      count++;
    }
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;



  }

  for(i = 0; i < N; i++){
    if(i == N-1){
      printf("%d\n", A[i]);
      break;
    }
    printf("%d ",A[i]);
  }

  printf("%d\n", count);
}

  

