#include<stdio.h>
void printmat(int A[],int N){
  int i;
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}
void insertionSort(int A[],int N){
  int i,j,insert;
  for(i=0;i<N;i++){
    insert = A[i];
    j=i-1;
    while(j >= 0&& A[j] > insert){
      A[j+1]=A[j];
      j--;
    A[j+1]=insert;
    }
    printmat(A,N);
  }
}
int main(){
  int N,i;
  int A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  insertionSort(A,N);
  return 0;
}

