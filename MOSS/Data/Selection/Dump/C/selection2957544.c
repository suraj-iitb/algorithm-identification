#include<stdio.h>

int main(){
  int N,i,j,min,temp,swap=0;
  int A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N;i++){
    min=i;
    for(j=i+1;j<N;j++){

      if(A[j]<A[min]) {
	min=j;
      }
    }
    if(i!=min){    
    temp=A[i];
    A[i]=A[min];
    A[min]=temp;
    swap++;
    }

  }
    for(i=0;i<N-1;i++){
      printf("%d ",A[i]);
    }
    printf("%d\n%d\n",A[N-1],swap);
  
} 

