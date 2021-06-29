#include<stdio.h>

void insertionSort(int*,int);
void print(int*,int);

int main(){
  int i,N;
  int A[1000];

  scanf("%d",&N);

  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }
  
  print(A,N);
  insertionSort(A,N);

  return 0;
}

void print(int *A,int N){
  int i;
  for(i = 0 ; i < N ; i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}
    

void insertionSort(int *A,int N){
  int i,j,v;

  for(i = 1 ; i < N  ; i++){
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
      A[j+1] = v;
    print(A,N);
  }
}
  

  

