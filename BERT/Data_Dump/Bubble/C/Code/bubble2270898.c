#include<stdio.h>
void bubbleSort(int* ,int);
int main(){
  int array[100];
  int N,i;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&array[i]);
  bubbleSort(array,N);
  return 0;
}
void bubbleSort(int *A,int N){
  int j;
  int flag=1,count=0;
  int keep;
  while(flag){
    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	keep=A[j];
	A[j]=A[j-1];
	A[j-1]=keep;
	flag=1;
	count++;
      }
    }
  }
  for(j=0;j<N-1;j++)
    printf("%d ",A[j]);
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
}
