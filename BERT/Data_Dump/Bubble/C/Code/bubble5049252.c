#include<stdio.h>

int bubbleSort(int A[] ,int N){
  int j,temp;
  int i=0;
  int count=0;
  
  for(i=0;i<(N-1);i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j] < A[j-1]){
	temp=A[j-1];
	A[j-1]=A[j];
	A[j]=temp;
	count++;	
      }
    }
  }
  return count;
}

int main()
{
  int i,N,count;
  int A[100];
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  count=bubbleSort(A,N);
  
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count); 
  return 0;
}
