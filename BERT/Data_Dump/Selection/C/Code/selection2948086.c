#include <stdio.h>

void selectionSort(int A[100],int N);

int main(){
  int A[100],N,i;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  selectionSort(A,N);
  return 0;
}

void selectionSort(int A[100],int N){
  int minj,i,j,count=0,tmp;
  for(i=0;i<N;i++){
    minj = i;

    for(j=i+1;j<N;j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
       if(minj != i){
	 tmp = A[i];
	 A[i] = A[minj];
	 A[minj] = tmp;
	  count++;
	}
    
  }

  for(i=0;i<N;i++){
    if(i==N-1){
      printf("%d\n",A[i]);
    }
    else{
      printf("%d ",A[i]);
    }
  }
  printf("%d\n",count);
}

