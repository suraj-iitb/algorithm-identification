#include<stdio.h>

void insertionSort(int *,int);
void print(int *,int);

int main(){
  int i,N;
  int A[1000];
  
  scanf("%d",&N);
  if(N <= 0 && N >= 100)return 0;
  
  for( i = 0 ; i < N ; i++ ){
    scanf("%d",&A[i]);
  }

  print(A,N);
  
  insertionSort(A,N);

  return 0;
}

void print(int *A ,int N){
  int i;
  for( i = 0 ; i < N ; i++ ){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
 
  printf("\n");
}

void insertionSort(int *A ,int N){
  int i,x,j;
  for( i = 1 ; i < N ; i++ ){
    x = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > x){
      A[j+1] = A[j];
      j--;
    }
      A[j+1] = x;
      print(A,N);
  }
}
     
      

