#include<stdio.h>

int main(){
  int N,A[100],i,j,a,minj,count=0,temp;

  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(j=0;j<N;j++){
    minj=j;
    for(i=j;i<N;i++){
      if(A[i] < A[minj]){
	minj=i;
      }
    }
    if(A[j] > A[minj]){
      temp=A[minj];
      A[minj]=A[j];
      A[j]=temp;
      count++;
    }
  }

  for(i=0;i<N-1;i++)
    printf("%d ",A[i]);

  printf("%d\n",A[i]);

  printf("%d\n",count);

  return 0;

}

    
  

