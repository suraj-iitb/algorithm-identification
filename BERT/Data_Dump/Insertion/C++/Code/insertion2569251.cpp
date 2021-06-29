#include <stdio.h>
void insertionsort(int numbers[],int size);
void swap(int *p_from,int *p_to);
int A[100];
int main(){
  int N,i,j;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf(" %d",&A[i]);
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  insertionsort(A,N);
  return 0;
}
void insertionsort(int A[],int size){
  int i,j,k;
  for(i=1;i<size;i++){
    j=i;
    while((j>0)&&(A[j-1]>A[j])){
      swap(&A[j-1],&A[j]);
      j--;
    }
    for(k=0;k<size-1;k++){
      printf("%d ",A[k]);
    }
    printf("%d\n",A[size-1]);
  }
}
void swap(int *p_from,int *p_to){
  int t;
  t=*p_from;
  *p_from=*p_to;
  *p_to=t;
}
