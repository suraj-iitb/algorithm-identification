#include<stdio.h>
#include<stdlib.h>

int main(){
  int A[1000]; 
  int i,j,k,v,N;

  scanf("%d",&N); 
  
  //constraint
  if(N<1 || N>100){
    exit(1);
  }

  //input array
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  //insertion sort
  for(i=1;i<N;i++){

    //output
    for(k=0;k<N;k++){
      if(k==N-1){
	printf("%d\n",A[k]);
	break;
      }
      printf("%d ",A[k]);
    }

    v=A[i];
    j=i-1;

    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
  }

  //output
  for(k=0;k<N;k++){
    if(k==N-1){
      printf("%d\n",A[k]);
      break;
    }
    printf("%d ",A[k]);
  }

  return 0;
}
  
