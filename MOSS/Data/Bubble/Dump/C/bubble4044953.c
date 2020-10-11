#include <stdio.h>

int bubbleSort(int A[], int N){
  int i,j,sw = 0,temp;

  for( i = 0; i < N; i ++){
    for( j = N - 1; j >= i + 1; j--){
      if( A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	if(i != j)
	sw ++;
      }
    }
  }
  return sw;
}
  

int main(){
  int A[100],N,i,sw;
  
  scanf("%d",&N);
  for( i = 0; i < N; i++)
    scanf("%d",&A[i]);

  sw = bubbleSort(A,N);

  for( i = 0; i < N; i++){
    if( i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",sw);

  return 0;
}

