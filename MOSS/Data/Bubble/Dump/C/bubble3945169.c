#include<stdio.h>

void trace(int A[],int N)
{
  for(int i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}


int bubbleSort(int A[],int N){
  int flag=1;
  int sw=0;
  while(flag){
    flag=0;
    for(int j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	int t=A[j];
	A[j]=A[j-1];
	A[j-1]=t;
	sw++;
	flag=1;
      }
    }
  }
  trace(A,N);
  return sw;
}

int main(void)
{
  int N;
  int A[100];
  int sw;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  sw=bubbleSort(A,N);
  printf("%d\n",sw);
  return 0;
}

