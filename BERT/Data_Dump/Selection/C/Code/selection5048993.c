#include <stdio.h>

int count=0;

void swap(int *x,int *y){
  int temp;

  count +=1;
  temp = *x;
  *x = *y;
  *y = temp;
  
}

void selectionSort(int A[],int N)
{
  int i,j,minj;

  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i+1;j<N;j++){
      if(A[j]<A[minj]){
	minj = j;
      }
    }
    if(i != minj) swap(&A[i],&A[minj]);
  }
}

  

int main(){
  int i,j,minj,N;

  scanf("%d",&N);

  int A[N];

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  selectionSort(A,N);
  
  for(i=0;i<N;i++){
    if(i==N-1){
      printf("%d",A[i]);
    }
    else printf("%d ",A[i]);
  }

  printf("\n%d\n",count);
  
  return 0;
}

