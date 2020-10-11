#include<stdio.h>
#define N 100

int selectionSort(int*,int);

int main(){
  int i,j,count,A[N];

  scanf("%d",&i);

  for(j=0;j<i;j++){
    scanf("%d",&A[j]);
  }

  count=selectionSort(A,i);

  printf("%d",A[0]);
  for(j=1;j<i;j++){
    printf(" %d",A[j]);
  }

  printf("\n%d\n",count);

  return 0;
}

int selectionSort(int *A,int n){
  int i,j,count=0,min,temp;

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(A[j]<A[min]) min=j;

    }

    if(i!=min){
      temp=A[i];
      A[i]=A[min];
      A[min]=temp;
      count++;
    }
      
  }

  return count;
}

