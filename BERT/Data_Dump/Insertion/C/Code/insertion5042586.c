#include <stdio.h>

int main()
{
  int a,i,j,N,A[100];

  scanf("%d",&N);

  for(i=0; i < N ;i++)
    {
      scanf("%d",&A[i]);
    } 
     

  for(i=1 ; i < N ; i++)
    {
     for(j=0 ; j < N ; j++)
	{
	  printf("%d",A[j]);
	  if(j+1 < N){printf(" ");}
	  else  printf("\n");
	}
     
      a = A[i];
      j =  i-1;

      while(j >= 0 && A[j] > a)
	{
	  A[j+1] = A[j];
	  j--;
	}
      A[j+1]=a;
    }

  for(j=0 ; j < N ; j++)
	{
	  printf("%d",A[j]);
	  if(j+1 < N){printf(" ");}
	  else printf("\n");
	}

  return 0;
}

