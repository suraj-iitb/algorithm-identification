#include<stdio.h>
#define n 100
int main(){

  int a,i,j,N,flag=1,A[n],count;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  while(flag){
    flag=0;
   for(j=(N-1);j>0;j--){
      if(A[j-1]>A[j]){
	a = A[j-1];
	A[j-1] = A[j];
	A[j] = a;
	flag=1;
	count++;
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}



   


