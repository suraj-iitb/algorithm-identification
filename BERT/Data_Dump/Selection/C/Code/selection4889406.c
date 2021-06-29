#include<stdio.h>
int selectionSort(int A[], int N)
{
 int i,j,t,sw = 0,w;
 for(i = 0;i< N-1;i++)
 {
 w = i;
 for(j = i;j<N;j++)
  {
  
  if(A[j] < A[w]) 
  w=j;
  }
   t= A[i];
   A[i] =A[w];
   A[w] = t;
   if ( i !=w) sw++;
  }
  return sw;
}

int main()
{
  int A[100],N,i,sw;

  scanf("%d",&N);
  for(i = 0;i<N;i++)
 {
  scanf("%d",&A[i]);
  }
  sw = selectionSort(A,N);

  for (i = 0;i <N;i++)
 {
  if (i>0)
  printf(" ");
  printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n", sw);

  return 0;
}


