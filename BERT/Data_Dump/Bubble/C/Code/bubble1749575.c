#include<stdio.h>

int bubbleSort(int*,int);

int main(){
  int A[100],N,sw;
  int i;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);
    sw=bubbleSort(A,N); 
    for(i=0;i<N;i++){
      if(i>0) printf(" ");
      printf("%d",A[i]);
    }
    printf("\n%d\n",sw);
  return 0;
}

int bubbleSort(int A[],int N){
  int sw=0,i,j;
  int flag=1;
  int swap;
  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	swap=A[j];
        A[j]=A[j-1];
	A[j-1]=swap;
	flag=1;
	sw++;
      }
    }
  }
  return sw;
}
