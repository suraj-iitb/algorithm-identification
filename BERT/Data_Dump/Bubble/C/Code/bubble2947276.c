#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int *A,int N);
int main(){
  int *A,i,N;
  scanf("%d\n",&N);
  A=(int *)malloc(N*sizeof(int));
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  bubbleSort(A,N);
  return 0;
}
void bubbleSort(int *A,int N){
  int flag=1,i,count=0,j,v;
  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	count++;
	v=A[j];
	A[j]=A[j-1];
	A[j-1]=v;
	flag=1;
      }
    }
  }

  for(i=0;i<N-1;i++){
    printf("%d",A[i]);
    printf(" ");
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
}



