#include<stdio.h>

int main(){

  int A[100],N,i,j,temp,tempcount=0,flag;  
  scanf("%d",&N);

  for(i=0 ; i<100 ;i++){
    A[i] = 0;
  }
  
  for(i=0 ; i<N ; i++){
    scanf("%d",&A[i]);
  }  

  flag = 1;
  while(flag){
    flag = 0;
    for(j=N-1 ; j>=1 ; j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag = 1;
        tempcount++ ;
      }
    }
  }

  for(i=0 ; i<N ; i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",tempcount);
  return 0;
}


