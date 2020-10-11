#include<stdio.h>
int main(){
  int A[100];
  int N;
  int i,j,minj,temp;
  int count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=N-1;i++){
    minj = i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
    if(A[i]!=A[minj]){
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    count++;
    }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}

