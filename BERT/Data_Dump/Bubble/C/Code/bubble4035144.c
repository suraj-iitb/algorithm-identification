#include <stdio.h>

void bubbleSort(int[],int);

int main(){
  int i,N;
  int A[100];
  
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);
  bubbleSort(A,N);
  
  return 0;
}

void bubbleSort(int A[],int N){
  int i,count=0,flag=1,kari;

   while(flag){
    flag = 0;
    for(i=N-1;i>0;i--){
      if(A[i] < A[i-1]){
	kari = A[i];
	A[i] = A[i-1];
      A[i-1] = kari;
      count++;
      flag = 1;
      }
    }
  }
   for(i=0;i<N;i++){
     printf("%d",A[i]);
     if(i != N-1)printf(" ");
   }
  printf("\n%d\n",count);
}

