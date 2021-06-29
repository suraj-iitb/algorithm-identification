#include <stdio.h>

void insertionSort(int[],int);
void printdata(int[],int);

int main(){
  int N,i;
  int A[1000];
  
  scanf("%d",&N);
  
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  printdata(A,N);
  insertionSort(A, N);
  return 0;
}


void insertionSort(int A[],int N){
  int i,v,j;
  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    printdata(A,N);
  }  
}
  void printdata(int A[],int N){
    int i;
    for(i=0;i<N;i++){
      if(i > 0) printf(" ");
      printf("%d",A[i]);
    }
    printf("\n");
  }
  

