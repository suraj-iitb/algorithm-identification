#include <stdio.h>
int selectionSort(int *,int );
int main(){
  int count,kazu,A[100],i;
  scanf("%d",&kazu);
  for(i=0;i<kazu;i++){
    scanf("%d",&A[i]);
  }
  count=selectionSort(A,kazu);
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

int selectionSort(int *A,int N){
  int minj,j,reset,count=0,i;
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]){
	minj=j;
      }

    }
    if(A[i]!=A[minj]){count++;}
    reset=A[i];
    A[i]=A[minj];
    A[minj]=reset;
    
  }
  
  return count;
}

  
      
  

