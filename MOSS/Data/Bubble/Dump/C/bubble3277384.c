#include<stdio.h>

int bubbleSort(int A[],int N);

int main(void){
  int A[100],N;
  int i;
  int num;

  scanf("%d",&N);

  for(i = 0;i < N;i++){
    scanf("%d",&A[i]);
  }

  num = bubbleSort(A,N);

  for(i = 0;i < N;i++){
    printf("%d",A[i]);
    if(i != N-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",num);

  return 0;
}
   
  
  


int bubbleSort(int A[],int N){
  int i,j,temp;
  int count = 0;
 
  for(i = 0;i < N-1;i++){
    for(j = N-1;i < j;j--){
      if(A[j] < A[j-1]){
	temp = A[j-1];
	A[j-1] = A[j];
	A[j] = temp;
	
	count++;
      }
    }
  }
  return count;
}



