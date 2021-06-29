#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *A,int N);
int main(){
  int *A,i,N,v,j;
  scanf("%d\n",&N);
  A=(int *)malloc(N*sizeof(int));
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
for(i=0;i<N-1;i++){
    printf("%d",A[i]);
    printf(" ");
  }
  printf("%d\n",A[N-1]);

  insertionSort(A,N);
  
  return 0;
}
void insertionSort(int *A,int N){
  int i,k,j,v;
  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    
    for(k=0;k<N-1;k++){
    printf("%d",A[k]);
    printf(" ");
    }
    printf("%d\n",A[N-1]);
    
  }
}

