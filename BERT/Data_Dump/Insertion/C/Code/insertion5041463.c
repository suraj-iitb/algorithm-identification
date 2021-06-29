#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int);

int main(){
    int A[1000],N,i;
    scanf("%d",&N);
    if(N<1 || N>100) exit(1);
    for(i=0;i<N;i++)
      scanf("%d",&A[i]);
    insertionSort(A, N);
}

void insertionSort(int *A, int N){
  int i,v,j;
  for(j=0;j<N-1;j++) printf("%d ",A[j]);
    printf("%d\n",A[j]);
  for(i=1;i<N;i++){
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }

    for(j=0;j<N-1;j++) printf("%d ",A[j]);
    printf("%d\n",A[j]);
  }
}
