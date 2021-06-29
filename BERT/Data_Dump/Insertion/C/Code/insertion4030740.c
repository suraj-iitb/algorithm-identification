#include<stdio.h>
#define N 100*2

int main()
{
  int l,A[N],i,v,j,k;
  
  scanf ("%d",&l);

  for(i=0;i<=l-1;i++)
    {
      scanf("%d",&A[i]);  
    }
  
  for(k=0;k<=l-1;k++)
    {
      printf("%d",A[k]);
      if( k < l-1 ) printf(" ");
    }
  printf("\n");
  
  for(i=1;i<l;i++)
    {
      
      v = A[i];
      j = i-1;
      
      while( j >= 0 && A[j] > v )
	{
	  A[j+1] = A[j];
	  j--;
	}
      A[j+1]=v;
      
      for(k=0;k<=l-1;k++)
	{
	  printf("%d",A[k]);
	  if( k < l-1 ) printf(" ");
	}
      printf("\n");
    }
  
  return 0;
}
      
      

