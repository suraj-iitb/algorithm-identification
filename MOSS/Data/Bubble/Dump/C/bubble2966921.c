#include<stdio.h>

int main(){

  int N,flag,sum=0,temp,i,j;
  int A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<(N-1);i++){

    for(j=N-1;j>i;j--){
      if(A[j-1]>A[j]){
      temp=A[j-1];
      A[j-1]=A[j];
      A[j]=temp;
      sum++;
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[N-1],sum);
}

