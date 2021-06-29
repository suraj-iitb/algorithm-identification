#include<stdio.h>
#include<stdlib.h>
#define c 10001

void CountingSort(int *,int *,int);
int N;

int main(){
  int i,k=0;
  int *A,*B;

  scanf("%d",&N);

  A=(int*)malloc((N+1)*sizeof(int));
  B=(int*)malloc((N+1)*sizeof(int));
  for(i=1;i<=N;i++){
    scanf("%d",&A[i]);
    if(k<A[i]){
      k=A[i];
    }
  }
  CountingSort(A,B,k);
  return 0;
}

void CountingSort(int *A,int *B,int k){
  int i,j,C[c];

  for(i=0;i<=k;i++){
    C[i]=0;
  }
  for(j=1;j<=N;j++){
    C[A[j]]++;
  }
  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=N;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<=N;i++){
    if(i==N){
      printf("%d\n",B[i]);
    }
    else{
      printf("%d ",B[i]);
    }
  }
}
  

  

