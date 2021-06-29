#include <stdio.h>
int bubbleSort(int *,int );
int main(){
  int kazu,A[100],count,i;
    scanf("%d",&kazu);
  for(i=0;i<kazu;i++){
    scanf("%d",&A[i]);
  }
  count=bubbleSort(A,kazu);
  for(i=0;i<kazu;i++){
    if(i!=kazu-1){
    printf("%d ",A[i]);
    }
    else{printf("%d",A[i]);
    }
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}


int bubbleSort(int *A,int N){
  int flag=1,reset,count=0;
  while(flag){
    flag=0;
    for(int j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	reset=A[j];
	A[j]=A[j-1];
	A[j-1]=reset;
	flag=1;
	count++;
      }
    }
  }
  
    return count;
}

    
  

