#include<stdio.h>
#include<stdlib.h>
#define N 10000
#define M 2000001

int num;
void CountingSort(int [ ], int [ ], int );

int main()
{

  int i=0,maxn=0,A[M],B[M];

  while(1)
    {
      scanf("%d",&num);
      if(num >= 1 && num <= M)
	  break;
    }

  while(i<num)
    {
      scanf("%d",&A[i]);
      if(A[i] >= 0 && A[i] <= N)
	{
	  if(maxn < A[i]) maxn = A[i];
	  i++;
	}
    }
  CountingSort(A,B,maxn);

  for(i=0;i<num-1;i++)
      printf("%d ",B[i]);
  printf("%d\n",B[i]);
  
  return 0;
}


void CountingSort(int a[], int b[], int k)
{
  int i,j,C[M];

  //C = malloc(sizeof(int) * k + 1);

  for(i=0;i<=k;i++)
    C[i] = 0;

  for(j=0;j<num;j++)
    C[a[j]]++;

  for(i=1;i<=k;i++)
    C[i] += C[i-1];

  for(j=num-1;j>=0;j--)
    {
      b[C[a[j]]-1] = a[j];
      C[a[j]]--;
    }
  //free(C);
}

