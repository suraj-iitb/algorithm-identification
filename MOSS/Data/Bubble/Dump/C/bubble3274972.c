#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *, int);

int main(){
  int A[100];
  int i, N;

  scanf("%d",&N);
  if(N < 1 || 100 < N) exit(1);

  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || 100 < A[i]) exit(2);
  }

  bubbleSort(A, N);

  return 0;
}

void bubbleSort(int *A, int N){
  int i, j, tem, num=0, flag=1;

  while(flag == 1){
    flag=0;
    for(j=N-1; j>=1; j--){
      if(A[j] < A[j-1]){
	tem=A[j];
	A[j]=A[j-1];
	A[j-1]=tem;
	flag=1;
	num++;
      }
    }
  }
  for(i=0; i<N; i++){
    if(i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", num);
}

