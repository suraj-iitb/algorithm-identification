#include<stdio.h>
int selectionSort(int A[],int N);
  
  int main(){
  int A[100],N,i,count;
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);
  count = selectionSort(A,N);
  for(i=0;i<N;i++){
    if(i > 0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);

  
  return 0;
}
int selectionSort(int A[],int N){
  int minj,i,j,count = 0,a;
  for (i = 0 ; i < N-1 ;i++){
    minj = i;
    for(j = i ; j < N ; j++){
    if( A[j] < A[minj] ) minj = j;
  }
  a = A[i];
  A[i] = A[minj];
  A[minj] = a;
  if( i != minj)count++;
}
return count;
}

