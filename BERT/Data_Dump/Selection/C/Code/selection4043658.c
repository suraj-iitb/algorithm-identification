#include<stdio.h>

void selectionSort(int A[],int);

int main(){
  int A[1000];
  int i,N;

  scanf("%d",&N);
   if(N <= 0 && N >= 100)return 0;

  for( i = 0 ;i < N ; i++ ){
    scanf("%d",&A[i]);
  }
  selectionSort(A,N);

  
  return 0;
}

void selectionSort(int A[],int N){
  int i,j,ex,count=0,minj;

  for( i = 0 ; i < N - 1 ; i++ ){
    minj = i;
    for( j = i ; j < N ; j++ ){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    ex = A[i];
    A[i] = A[minj];
    A[minj] = ex;
    if(i != minj)count++;
  }
  for( i = 0 ; i < N ; i++ ){
    if( i > 0 )printf(" ");
    printf("%d",A[i]);
  }

  printf("\n%d\n",count);
}

  

