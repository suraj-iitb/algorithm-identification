#include<stdio.h>
#define X 1000
void insertionSort(int A[], int N);

int main(){
  int N,i,j;
  int A[X];

  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  insertionSort(A,N);
  return 0;
}

void insertionSort(int A[], int N){
  int i,j,v;
  for(i=0;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1] = v;
    for(j=0;j<N;j++){
    if(j>0) printf(" ");
    printf("%d",A[j]);
    }
    printf("\n");
  }
}
