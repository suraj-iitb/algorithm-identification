#include <stdio.h>

void trace(int A[], int N){
  int i;
  for (i = 0; i < N; i++){
    if(i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int bubbleSort(int A[], int N){
  int flag = 1, i = 0, j, a;
  while(flag == 1){
    flag = 0;
    for(j = N-1; j > 0; j--){
      if(A[j] < A[j-1]){
	a = A[j];
	A[j] = A[j-1];
	A[j-1] = a;
	flag = 1;
	i++;
      }
    }
  }
  return i;
}

int main(){
  int A[100], N, i, count = 0;

  scanf("%d", &N);
  
  for(i = 0; i < N; i++) scanf("%d", &A[i]);
  
  count = bubbleSort(A, N);
  trace(A, N);
  printf("%d\n", count);
  
  return 0;
}

