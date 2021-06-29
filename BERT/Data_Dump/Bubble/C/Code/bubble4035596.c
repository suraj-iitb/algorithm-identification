#include <stdio.h>
int bubbleSort(int A[],int N);



int main()
{
  int A[100];
  int i;
  int N;
  int count;
  
  scanf("%d",&N);
  for( i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  
  count =  bubbleSort(A,N);

  for( i = 0; i < N; i++){
    if( i > 0 )printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}



int bubbleSort( int A[],int N)
{
  int flag = 1;
  int i=0;
  int j;
  int c;
  while(flag == 1){
    flag = 0;
    for( j = N-1; j >= 1; j--){
      if( A[j] < A[j-1]){
	
	c = A[j];
	A[j] = A[j-1];
	A[j-1] = c;
	flag = 1;
	i++;
	
      }
    }
  }

  return i;
}

