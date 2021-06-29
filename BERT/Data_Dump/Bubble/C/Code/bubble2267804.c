#include<stdio.h>

int main( ){

  int A[100],flag=1,j,N,a,count=0;


  scanf("%d",&N);

  for(j=0;j<N;j++){
    scanf("%d",&A[j]);
  }
  

  while(flag){

    flag=0;

    for(j=1;j<N;j++){

      if(A[j]<A[j-1]){
	a=A[j];
	A[j]=A[j-1];
	A[j-1]=a;

	flag=1;
	count++;
       
      }

    }

  }


  for(j=0;j<N;j++){
    
    if(j==N-1)printf("%d\n",A[j]);
    else  printf("%d ",A[j]);
  }

  printf("%d\n",count);

  
    return 0;
}
