#include<stdio.h>

void selectionsort(int *,int);

void selectionsort(int *A,int N)
{
  int a,minj,i,j,count=0;

  for(i=0;i<N-1;i++) {
    minj = i;
    for(j=i;j<N;j++){
      if(A[j] < A[minj]) 
	minj = j;
    }
    a = A[i];
    A[i] = A[minj];
    A[minj] = a;
    if(i != minj)
    count++;
  }
    
  for(i=0;i<N;i++) {
    printf("%d",A[i]);
    if(i<N-1)printf(" ");
  }

  printf("\n");

  printf("%d\n",count);
}

int main()
{
    int N,A[100],i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    scanf("%d",&A[i]);
    
    selectionsort(A,N);

    return 0;
}

