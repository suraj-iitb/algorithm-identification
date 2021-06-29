#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *A,int N);
     
int main(){
  int i;
  int N;
  int A[100];
  scanf("%d",&N);
  if(1<=N && N<=100){
    for(i = 0;i < N;i++){
      scanf("%d",&A[i]);
      if(0 > A[i] || A[i] > 1000) exit(2);
    }
  }
  else exit(1);
  
  for(i = 0;i < N;i++){
    if(i)printf(" ");
    printf("%d",A[i]);
  }
  
  printf("\n");
  insertionSort(A,N);
  return 0;
}

void insertionSort(int *A,int N){
  int i,j,v;
  int c;
  for( i=1 ; i<=N-1 ; i++ ){
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(c=0;c<N;c++){
      if(c)printf(" ");
      printf("%d",A[c]);
    }
    printf("\n");
  }
}

