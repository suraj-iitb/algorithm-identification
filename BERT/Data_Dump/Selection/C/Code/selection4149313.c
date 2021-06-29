#include<stdio.h>
int selectionSort(int A[],int N){
  int i,j,swap=0,min,tmp;
  for(i=0;i<N-1;i++){
    min = i;
    for(j=i;j<N;j++){
      if(A[j]<A[min])min=j;
    }
    tmp = A[i];A[i]=A[min];A[min]=tmp;
    if(i !=min )swap++;
  }
  return swap;
}
int main(){
  int A[100],N,i,swap;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  swap=selectionSort(A,N);
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",swap);

  return 0;
}
