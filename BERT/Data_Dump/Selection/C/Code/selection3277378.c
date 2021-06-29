#include <stdio.h>

void selectionSort(int[],int);

int main(){
  int N,i;
  int A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  selectionSort(A,N);
  return 0;
}

void selectionSort(int A[],int N){
  int i,min,j,a,count=0;

  for(i=0;i<N-1;i++){
    min = i;
    for(j=i;j<N;j++){
      if(A[j]<A[min])min = j;
    }
    a = A[i];
    A[i] = A[min];
    A[min] = a;
    
    if(i!=min)count++;
  }

  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
}

