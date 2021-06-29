#include <stdio.h>

int main()
{
  int N, i, j, A[100], store, count = 0, flag;
  
  scanf("%d", &N);
  for(i=0; i <= N-1; i++)
    {
      scanf("%d",&A[i]); 
    }
  flag = 1;
  i = 0;
  while(flag == 1){
    flag = 0;
    for(j = N-1; j >= i+1; j--)
      {
	if (A[j] < A[j - 1])
	  {
	    store = A[j];
	    A[j] = A[j-1];
	    A[j-1] = store;
	    flag = 1;
	    count++;
	  }
      }
    i++;
  }
  for(i=0; i <= N-1; i++)
    {
      printf("%d",A[i]);
      if(i != N-1)
	{
	  printf(" ");
	}
      else
	{
	  printf("\n");
	}
    }
  printf("%d\n", count);
  return 0;
}

