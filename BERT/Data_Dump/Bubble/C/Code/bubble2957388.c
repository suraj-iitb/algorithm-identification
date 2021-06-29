#include<stdio.h>
int main(){
  int flag = 1;
  int i,tmp,N,count=0;
  int A[100];

  scanf("%d",&N);
 
  for( i=0 ; i<N ; i++ ){
    scanf("%d",&A[i]);
  }
  
  while(flag){
    flag = 0;
    for( i=N-1 ; i>0 ; i-- ){
      if(A[i] < A[i-1]){
	tmp = A[i];
	A[i] = A[i-1];
	A[i-1] = tmp;
	count++;
  	flag = 1;
      }
    }
  }

  for( i=0 ; i<N-1 ; i++)
    printf("%d ",A[i]);

  printf("%d",A[N-1]);
  printf("\n%d\n",count);
    
  return 0;
}

