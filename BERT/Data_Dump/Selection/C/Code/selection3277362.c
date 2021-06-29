#include <stdio.h>

int selectionSort(int *,int);

int main(){
  int N,j;
  int A[100];
  int sw =0;

  scanf("%d",&N);

  for(j=0; j < N;j++){
    scanf("%d",&A[j]);
  }

  sw = selectionSort(A,N);

  for(j=0 ;j < N;j++){

    if(j > 0)printf(" ");

    printf("%d",A[j]);
  }


  printf("\n%d\n",sw);

  return 0;
}


int selectionSort(int A[],int N){
  int i,j,minj,temp;
  int sw = 0;

  for(i=0 ;i < N -1;i++){
    minj = i;

    for(j=i ;j < N;j++){

      if( A[j] < A[minj] )minj = j;
      
      }

	temp = A[i];
	A[i] = A[minj];
	A[minj] = temp;

	if( i != minj )sw++;
  
  }

  return sw;
}

	

