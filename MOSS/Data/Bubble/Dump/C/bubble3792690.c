#include<stdio.h>


void bubbleSort(int A[101],int N){
  int flag=1,t=0,k=0;
  while(flag==1){

    flag=0;

    for(int j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
        t=A[j];
        A[j]=A[j-1];
        A[j-1]=t;
        flag=1;
        k++;
      }
    }
  }
  for(int i=0;i<N;i++){
    if(i==N-1){
        printf("%d\n",A[i]);
        break;
    }
    printf("%d ",A[i]);
  }
  printf("%d\n",k);
}


int main(void){
  int N,A[101]={};

  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  bubbleSort(A,N);


  return 0;
}

