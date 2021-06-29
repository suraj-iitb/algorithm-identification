#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b) (a += b,b = a - b,a -= b)
#define M 100

void bubbleSort(int *A,int N);

int main(){
  int N;
  int i;
  int A[M];
  scanf("%d",&N);
  if(N < 1 || M < N) exit(1);
  for( i = 0 ; i < N ; i++ ){
    scanf("%d",&A[i]);
    if(A[i]< 0 || A[i] > 100) exit(2);
  }
  bubbleSort(A,N);
  return 0;
}

void bubbleSort(int *A,int N){
  int i,j;
  int flag = 1;
  int temp;
  int c = 0;
  
  while(flag){
    flag = 0;
    for(j = N-1 ; j >= 1 ; j-- ){
      if(A[j] < A[j-1]){
        SWAP(A[j],A[j-1]);
        c++;
        flag = 1;
      }
    }
  }
  for( i = 0 ; i < N ; i++ ){
    if(i)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",c);
}

