#include <stdio.h>

int selectionSort(int A[],int N);


int main()
{
  int A[100];
  int N;
  int i;
  int count;

  scanf("%d",&N);
  for( i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  
  count =  selectionSort(A,N);
  
  for( i = 0; i < N; i++){
    if( i > 0 )printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}


int selectionSort(int A[],int N)
{
  int i,j;
  int minj;
  int c;
  int count=0;
  for( i = 0; i < N; i++){
    minj = i;
    for( j = i; j < N; j++){
      if( A[j] < A[minj]){
	minj = j;
      }
    }
	c = A[i];
	A[i] = A[minj];
	A[minj] = c;
	if(i != minj) count++;
  }
  

      return count;
	
}
    
  

