#include <stdio.h>

int selectionSort(int *,int);

int main()
{
   int A[100],N,i,sw;

  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);
  
  sw = selectionSort(A,N);
  
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",sw);

  return 0;

}

int selectionSort(int A[],int N)
{
  int i,j,minj,s,sw;

  sw = 0;

  for(i=0;i<=N-1;i++){
    minj = i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj])minj = j;
    }
    s = A[i];
    A[i] = A[minj];
    A[minj] = s;

    if(i!=minj)sw++;
    }
    return sw;
  }
	
    

