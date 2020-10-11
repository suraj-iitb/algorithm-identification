#include <stdio.h>

void selectionSort(int[],int);

int main(){
  int i,N;
  int A[100];
  
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);
  selectionSort(A,N);
  
  return 0;
}

void selectionSort(int A[],int N){
  int i,j,count=0,minj,kari;

  for(i=0;i<N-1;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    kari = A[i];
    A[i] = A[minj];
    A[minj] = kari;
    if(minj != i)count++;
  }
  
  
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i != N-1)printf(" ");
  }
  printf("\n%d\n",count);
}
  

