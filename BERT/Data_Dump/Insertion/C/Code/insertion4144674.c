#include<stdio.h>

void insertionSort(int *,int);

int main(){
  int i,N,A[1000];

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  for(i=0;i<N-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[i]);

  insertionSort(A,N);
  
  return 0;
  
}

void insertionSort(int *A,int N){
  int i,j,k,v;
  
  for(i=1;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    
    /*計算の途中経過表示*/
    for(k=0;k<N-1;k++) printf("%d ",A[k]);
    printf("%d\n",A[k]);
  }
}

