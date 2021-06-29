#include <stdio.h>
#include <stdlib.h>

int selectionSort(int *,int);

int main()
{
  int i,A[100],cnt,N;
  
  scanf("%d",&N);
  if(N<1 || N>100) exit(1);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  cnt = selectionSort(A,N);

  for(i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  
  return 0;
}

int selectionSort(int A[],int N)
{
  int i,j,tmp,cnt=0,minj;

  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j] < A[minj])
	minj = j;	 
    }
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    if(i != minj)
      cnt++;
  }
  return cnt;
}

