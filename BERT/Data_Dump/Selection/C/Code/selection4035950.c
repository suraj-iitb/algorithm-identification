#include <stdio.h>

void selectionSort(int* , int );
  
int main(){

  int i,j,k,N,A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  selectionSort(A, N);
  
   

  return 0;
}

void selectionSort(int *A, int N){
  int i,j,k=0,minj=0,tmp;

  for(i=0;i<N;i++){
    minj=i;
    for(j=i+1;j<N;j++){
      if (A[j] < A[minj]){
	minj = j;
      }
    }
	tmp=A[i];
	A[i]=A[minj];
	A[minj]=tmp;
	if(i!=minj)k++;
  }
  

  for(j=0;j<N-1;j++) printf("%d ",A[j]);
    printf("%d\n",A[N-1]);
    printf("%d\n",k);
}

