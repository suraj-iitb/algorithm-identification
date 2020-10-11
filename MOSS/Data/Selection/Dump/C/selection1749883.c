#include<stdio.h>
int selectionSort(int* ,int);
int main(){
  int i,sw,A[100],N;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);
  sw=selectionSort(A,N);
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
  printf("%d",A[i]);
  }
  printf("\n%d\n",sw);
  return 0;
}
int selectionSort(int A[],int N){
  int j,i,minj;
  int sw=0,swap;
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj])
      minj=j;
    }
    if(i!=minj){
      swap=A[i];
      A[i]=A[minj];
      A[minj]=swap;
      sw++;
    }
  }
  return sw;
}
