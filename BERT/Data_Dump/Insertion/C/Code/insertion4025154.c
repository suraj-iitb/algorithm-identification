#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *,int);
void print(int *,int);
int main(){
  int *A;
  int i,n;
  
  scanf("%d",&n);
  A=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  print(A,n);
  insertionSort(A,n);

  return 0;
}
void insertionSort(int *A,int N){
  int i,j,k,key;
  for(i=1;i<N;i++){
    key=A[i];
    j=i-1;
    while(j>=0&&A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
    print(A,N);
  }
}
void print(int *A,int N){
  int i;
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

