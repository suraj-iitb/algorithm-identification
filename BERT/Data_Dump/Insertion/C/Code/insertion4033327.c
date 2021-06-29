#include <stdio.h>
#define NMAX 100

int insertionSort(int,int *);

int main(void){
  int i,N,A[NMAX];
  scanf("%d",&N);
  for(i = 0;i < N;i++){
    scanf("%d",&A[i]);
  }
    insertionSort(N,A);

    return 0;
  }

int insertionSort(int N,int *A){

  int i,j,key,k;

  for(i = 0;i < N;i++){

    key = A[i];
    j = i - 1;
    while((j >= 0) && (A[j] > key)){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    for(k = 0;k < N;k++){
      if(k == N-1) printf("%d\n",A[k]);
      else printf("%d ",A[k]);
    }
  
  }		      
  return 0;
}


