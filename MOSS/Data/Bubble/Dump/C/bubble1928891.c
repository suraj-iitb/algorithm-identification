#include <stdio.h>

int N, A[100], temp, count;

void bubbleSort(){
  int i=0, j;
  while(i!=N){
    for(j=N-1; j>=i+1; j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	count++;
      }
    }
    i++;
  }
}

int main(){
  int i;
    scanf("%d", &N);
  for(i=0; i<N; i++)scanf("%d", &A[i]);
  bubbleSort();
  for(i=0; i<N-1; i++){
    printf("%d ", A[i]);
  }
  printf("%d\n%d\n", A[i], count);
  return 0;
}
