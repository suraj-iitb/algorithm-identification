#include<stdio.h>

void selectionSort(int A[],int N){
  int i,j,minj,temp;
  int count=0;

  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]) minj=j;
    }
    temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
    if(i!=minj)count++;
  }
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
}
  
int main()
{
  int A[100];
  int i,N,count;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  selectionSort(A,N);

  return 0;
}

