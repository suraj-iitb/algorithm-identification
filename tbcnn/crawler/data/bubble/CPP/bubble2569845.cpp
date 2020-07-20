#include <stdio.h>
void bubblesort(int A[],int N);
int main(){
  int N,A[100],i,t,count;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  bubblesort(A,N);
  return 0;
}
void bubblesort(int A[],int N){
  int i,j,t,count=0;
  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(A[j-1]>A[j]){
        t=A[j-1];
        A[j-1]=A[j];
        A[j]=t;
        count++;
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[N-1],count);
}
