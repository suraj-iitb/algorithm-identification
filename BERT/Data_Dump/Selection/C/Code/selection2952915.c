#include<stdio.h>
#include<stdlib.h>
void selectionSort(int *A,int N);
int main(){
  int *A,i,N;
  scanf("%d\n",&N);
  A=(int *)malloc(N*sizeof(int));
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  selectionSort(A,N);
  return 0;
}
void selectionSort(int *A,int N){
  int i,j,v,k,minj,count=0;
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    v=A[i];
    A[i]=A[minj];
    A[minj]=v;
    if(A[minj]!=A[i])count++;
  }
  for(i=0;i<N-1;i++){
    printf("%d",A[i]);
    printf(" ");
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
}

