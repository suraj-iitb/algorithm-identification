#include<stdio.h>

void bubbleSort(int A[],int N);

int count=0;

int main()
{

  int i;
  int A[100],N;

    scanf("%d",&N);
  for(i=0;i<N;++i){
    scanf("%d",&A[i]);
  }

  bubbleSort(A,N);

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
 }

void bubbleSort(int A[],int N)
{
  int i,j,temp;

  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	count++;
      }
    }
  }
 

}
