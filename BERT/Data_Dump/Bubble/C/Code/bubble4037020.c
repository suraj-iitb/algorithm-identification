#include<stdio.h>

int main(){

  int i,N,A[100],a,count=0,t=0;
  scanf("%d",&N);

  for(i=0;i<N;i++) scanf("%d",&A[i]);

  while(t!=N-1){
    for(i=N-1;i>=1+t;i--){
      if(A[i]<A[i-1]){
	a=A[i-1];
	A[i-1]=A[i];
	A[i]=a;
	count++;
      }
    }
    t++;
  }
  
  for(i=0;i<N;i++){
    printf("%d",A[i]);  
    if(i!=N-1) printf(" ");
  }
  printf("\n%d\n",count);
  
  return 0; 
}

