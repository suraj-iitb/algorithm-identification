#include<stdio.h>
#include<stdlib.h>


int main(){
  int flag=1;
  int *A;
  int j;
  int num;
  int N;
  int sum=0;

  scanf("%d",&N);
  A=(int *)malloc(num*sizeof(int));
  for(j=0;j<N;j++)
    scanf("%d",&A[j]);

  while(flag){
    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	num=A[j];
	A[j]=A[j-1];
	A[j-1]=num;
	sum++;
	flag=1;
      }
    }
  }
  for(j=0;j<N-1;j++)printf("%d ",A[j]);
  printf("%d\n%d\n",A[j],sum);
  


  
  return 0;
}
  
  

