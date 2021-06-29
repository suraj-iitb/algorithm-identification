#include <stdio.h>

void insertionSort(int*, int);

int main(){
  int i;
  int j;
  scanf("%d", &i);
  int A[i];
  for(j=0;j<i;j++){
    scanf("%d", &A[j]);
  }
  for(j=0;j<i;j++){
    printf("%d", A[j]);
    if(j!=i-1)printf(" ");
    
  }
  printf("\n");
  insertionSort(A,i);
  return 0;
}

void insertionSort(int *A,int N){

  int i,j,v;
  
  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(j=0;j<N;j++){
    printf("%d", A[j]);
    if(j!=N-1)printf(" ");
    }
    printf("\n");
  }
}

