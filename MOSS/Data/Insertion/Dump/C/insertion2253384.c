#include <stdio.h>

void insertionSort(int *,int);
void abc(int *,int);

int main(){

  int N,i,j;
  int A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
      }
  insertionSort(A,N);
  
  return 0;
}

void insertionSort(int A[],int N){
  int i,j,v;

  abc(A,N);
  for(i=1;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    abc(A,N);
  }
}

void abc(int A[],int N){
  int i;

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1) printf(" ");
  }
  printf("\n");
}
  
