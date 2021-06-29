#include<stdio.h>

int main(){
  int N,A[100],i,j,a,count;

  scanf("%d",&N);
  
  if((1<=N)&&(N<=100)){
    for(i=0;i<N;i++){
      scanf("%d",&A[i]);
    }
  }
  for(j=0;j<N;j++){
    for(i=N-1;i>j;i--){
      if (A[i] < A[i-1]){
	a=A[i];
	A[i]=A[i-1];
	A[i-1]=a;
	count++;
      }
    }
  }
  for(i=0;i<N-1;i++)
    printf("%d ",A[i]);

  printf("%d\n",A[i]);
  
  printf("%d\n",count);

  return 0;
}

    
  

