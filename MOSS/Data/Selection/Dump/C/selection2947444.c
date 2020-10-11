#include <stdio.h>

int selectionSort(int *,int);

int main(){
  int i=0;
  int j=0;
  int count=0;
  scanf("%d", &i);
  int A[i];
  for(j=0;j<i;j++){
    scanf("%d",&A[j]);
  }
  count=selectionSort(A,i);
  for(j=0;j<i;j++){
    printf("%d",A[j]);
    if(j!=i-1)printf(" ");
  }
  printf("\n");
  printf("%d",count);
  printf("\n");
  return 0;
}

int selectionSort(int *A,int N){
  int i=0;
  int j=0;
  int count=0;
  int minj=0;
  int swapnumber=0;
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(i!=minj){
      swapnumber=A[i];
      A[i]=A[minj];
      A[minj]=swapnumber;
      count++;
    }
  }
  return count;
}

