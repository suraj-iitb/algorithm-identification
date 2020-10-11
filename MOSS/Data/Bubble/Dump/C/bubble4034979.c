#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int *,int);

int main()
{
  int N,A[100],i,j,cnt;

  scanf("%d",&N);
  if(N>100 || N<1) exit(1);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  cnt = bubbleSort(A,N);
  
  for(j=0;j<N;j++){
    if(j) printf(" ");
    printf("%d",A[j]);
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

int bubbleSort(int A[],int N)
{
  int flag=1,cnt=0,i,tmp;

  while(flag)
    {
      flag=0;
      for(i=N-1;i>0;i--)
	{
	  if(A[i] < A[i-1])
	    {
	      tmp = A[i];
	      A[i] = A[i-1];
	      A[i-1] = tmp;
	      flag=1;
	      cnt++;
	    }
	}
    }
  return cnt;
}

