#include<stdio.h>
#include<stdlib.h>
int c=0;

int* Selection(int *A, int N){
  int i, j, minj, num;
  for(i=0 ; i<N ; i++){
    minj=i;
    for(j=i ; j<N ; j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
    num=A[i];
    A[i]=A[minj];
    A[minj]=num;
    if(A[i]!=A[minj])c++;
  }
  return A;
}

int main(void){
  int N,i;
  int *A;
  scanf("%d",&N);
  A = (int*)malloc(sizeof(int)*N);
  for(i=0 ; i<N ; i++){
    scanf("%d",&A[i]);
  }
  A=Selection(A,N);
  printf("%d",A[0]);
  for(i=1 ; i<N ; i++){
    printf(" %d",A[i]);
  }
  printf("\n%d\n",c);
  return 0;
}
