#include <stdio.h>

void bubbleSort(int* , int );
  
int main(){

  int i,j,k,N,A[100],v;

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  bubbleSort(A, N);
  
   

  return 0;
}

void bubbleSort(int *A, int N){
  int i=0,j,flag,tmp;

  flag=1;
  while(flag){
    flag=0;
  for(j=N-1;j>0;j--){
    if(A[j]<A[j-1]){
      tmp=A[j];
      A[j]=A[j-1];
      A[j-1]=tmp;
      flag=1;
      i++;
    }
  }
  }

  for(j=0;j<N-1;j++) printf("%d ",A[j]);
    printf("%d\n",A[N-1]);
    printf("%d\n",i);
}

