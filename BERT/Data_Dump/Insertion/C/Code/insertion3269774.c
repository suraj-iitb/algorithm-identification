#include <stdio.h>
#define N 100

int main ()
{
  int A[1000],i,j,v,data,a;

  scanf("%d",&data);
  for(i=0;i<data;i++)
    {
      scanf("%d",&A[i]);
    }
  for(i=1;i<data;i++)
    {
      for(a=0;a<data;a++)
	{
	printf("%d",A[a]);
	if(a<data-1)
	  printf(" ");
	}
      v=A[i];
      j=i-1;
      while(j>=0&&A[j]>v)
	{
	  A[j+1]=A[j];
	  j--;
	}
      A[j+1]=v;
      printf("\n");
    }
  for(i=0;i<data;i++)
	{
	printf("%d",A[i]);
	if(i<data-1)
	  printf(" ");
	}

      printf("\n");
      return 0;
}

