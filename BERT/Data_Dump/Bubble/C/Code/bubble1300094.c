#include<stdio.h>

int main(void){
  int N,A[100],swap,i,n,num=0,f=1;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  while(f){
    f=0;
    for(i=N-1;i>=0;i--){
      if(A[i]<A[i-1]){
	swap=A[i-1];
	A[i-1]=A[i];
	A[i]=swap;
	num++;
	f=1;
      }
   
    }
  } 
  for(n=0;n<N-1;n++){
    printf("%d ",A[n]);
  }
  printf("%d\n%d\n",A[n],num);
  return 0;
}
