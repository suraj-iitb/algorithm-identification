#include <stdio.h>
int selectionSort(int *,int);

int main(){
  int A[100],N;
  int i,count;

  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  count = selectionSort(A,N);
  for(i=0; i<N-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",count);
  return 0;
}

int selectionSort(int *A,int N){
  int i,j,minj,temp,count=0;

  for(i=0; i<=N-1; i++){
    minj = i;
    for(j=i; j<=N-1; j++){
      if(A[j] < A[minj])
	minj = j;
    }
    if(A[i] != A[minj]){
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      count++;
    }
  }
  return count;
}
