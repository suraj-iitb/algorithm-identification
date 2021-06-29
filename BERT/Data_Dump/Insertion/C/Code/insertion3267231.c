#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int);

int main(){
  int i, N;
  int A[100];

  scanf("%d",&N);
  if(N < 1 || 100 < N) exit(1);
  
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || 1000 < A[i]) exit(2);
  }

  insertionSort(A, N);

  return 0;
}

void insertionSort(int *A, int N){
  int h, i, j, k, v;

  for(h=0; h<N; h++){
    if(h) printf(" ");
    printf("%d", A[h]);
  }
  printf("\n");
  for(i=1; i<=N-1; i++){
    v=A[i];
    j=i-1;
    while(j >= 0 && A[j] > v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(k=0; k<N; k++){
      if(k) printf(" ");
      printf("%d", A[k]);
    }
    printf("\n");
  }
}

  
    
  
  

