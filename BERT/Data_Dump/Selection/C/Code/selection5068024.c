#include <stdio.h>

int selectionSort(int* ,int);

int main( )
{
  int A[100],i,N,count;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  count = selectionSort(A, N);

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1) printf(" ");
  }
  printf("\n");

  printf("%d\n",count);

  return 0;
}

int selectionSort(int A[],int N)
{
  int minj,i,j,tmp,count=0;
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
      tmp=A[i];
      A[i]=A[minj];
      A[minj]=tmp;
      if(i != minj) count++;
  }
  return count;
}

