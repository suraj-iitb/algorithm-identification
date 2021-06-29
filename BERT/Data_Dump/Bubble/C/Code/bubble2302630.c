#include <stdio.h>

int bubblesort(int A[],int N)
{
  int i,j,v;
  int count = 0;
  for(i = 0; i < N - 1; i++)
  {
    for(j = N - 1; j > i; j--)
    {
      if(*(A + j) < *(A + j - 1))
      {
        v = 0;
      	v = *(A + j);
        *(A + j) = *(A + j - 1);
        *(A + j - 1) = v;
        count++;
      }
    }
  }
  return count;
}

int main()
{
  int N,count,i;
  int A[100];
  
  scanf("%d",&N);
  for(i = 0; i < N; i++)
  {
    scanf("%d",A + i);
  }
  
  count = bubblesort(A,N);
  
  for(i = 0; i < N; i++)
  {
    if(i > 0)
  	{
  		printf(" ");
  	}
  	printf("%d",*(A + i));
  }
	printf("\n");
	printf("%d\n",count);
	
	return 0;
}
