#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b) (a += b,b = a - b,a -= b)
#define M 100

void selectionSort(int *A,int N);

int main(){
  int N;
  int i;
  int A[M];
  scanf("%d",&N);
  if(N<1 || N>M) exit(1);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
    if(A[i]< 0 || A[i]>M) exit(2);
  }
  selectionSort(A,N);
  return 0;
}

void selectionSort(int *A,int N){
  int i,j;
  int minj;
  int temp;
  int c=0;
  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    temp = A[i];
	A[i] = A[minj];
	A[minj] = temp;
	if(A[minj] != A[i]) c++;
  }
  for(i=0;i<N;i++){
    if(i)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",c);
  
}
