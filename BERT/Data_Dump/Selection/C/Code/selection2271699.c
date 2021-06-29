#include <stdio.h>
int selectionSort(int[], int);
int main(){
  int i,N;
  scanf("%d",&N);
  int A[N];
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  selectionSort(A,N);
  return 0;
}

int selectionSort(int A[],int N){
  int i,j = 0,tmp;
  int minj;
  int count = 0;
  for(i = 0; i <= N-1; i++){
    minj = i;
    for(j = i; j <= N-1; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    if( i != minj ){
     tmp = A[i];
     A[i] = A[minj];
     A[minj] = tmp;
     count++;
    }
  }
  for(i = 0; i < N; i++){
    if(0 < i){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);
}
