#include<stdio.h>

void trace(int A[],int N)
{
  for(int i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}


int selectionSort(int A[],int N){
  int sw=0;
  for(int i=0;i<N;i++){
    int minj=i;
    for(int j=i;j<N;j++){
      if(A[j]<A[minj]) minj=j;
	int t=A[j];
	
    }
    if(i!=minj){
    int t=A[i];
    A[i]=A[minj];
    A[minj]=t;
    sw++;
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
  sw=selectionSort(A,N);
  printf("%d\n",sw);
  return 0;
}

