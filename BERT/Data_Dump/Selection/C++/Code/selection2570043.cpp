#include <stdio.h>
void selectionsort(int A[],int N);
int main(){
  int i,N,A[100],MIN;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  selectionsort(A,N);
  return 0;
}
void selectionsort(int A[],int N){
  int i,j,k,MIN,t,count=0;
  for(i=0;i<N-1;i++){
    MIN=A[i];
    for(j=i+1;j<N;j++){
      if(MIN>A[j]){
        MIN=A[j];
        k=j;
      }
    }
    if(MIN!=A[i]){
      t=A[i];
      A[i]=A[k];
      A[k]=t;
      count++;
    }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[N-1],count);
}
