#include<stdio.h>
int selectionSort(int[], int);
int main(){
  int i, N, con;
  int A[100];

  scanf("%d",&N);
  for( i = 0 ; i < N ; i++ ){
    scanf("%d",&A[i]);
  }
  
  con = selectionSort(A, N);

  printf("%d",A[0]);
  for( i = 1 ; i < N ; i++ ){
    printf(" %d",A[i]);
  }
  printf("\n%d\n",con);
  return 0;
}

int selectionSort(int A[], int N){
  int i, j, con=0, minj, tmp;
  for( i = 0 ; i < N ; i++ ){
    minj = i;
    for( j = i ; j < N ; j++ ){
      if( A[j] < A[minj] ) minj = j;
    }
    if( i != minj ) con++;
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
  }
  return con;
}

