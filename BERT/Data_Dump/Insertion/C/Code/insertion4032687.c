#include<stdio.h>

void insertionSort(int *,int );
void trace(int *, int);
int main() {
  int N,i ,j;
  int A[1000];
  scanf("%d",&N);
  for(i = 0; i < N; i++)
    scanf("%d",&A[i]);
  trace(A,N);
  insertionSort(A,N);
  return 0;
}
void trace(int A[],int N){
  int i;
  for(i = 0; i < N; i++){
    if(i > 0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

void insertionSort(int A[],int N){
  int j,k,key;
  for(j = 1; j < N; j++){
    key = A[j];
    k = j - 1;
    while(k >= 0 && A[k] > key){
      A[k+1] = A[k];
      k--;
    }
    A[k+1] = key;
    
    trace(A,N);
  }
}


