#include <stdio.h>

int main()
{
  int i,j,k,key;
  int l;
  int A[100];
  
  scanf("%d",&l);
  
  for(i=0;i<l;i++)
    {
      scanf("%d",&A[i]);
    }
  
  for(i=0;i<l-1;i++)
    {
      printf("%d ",A[i]);
    }

  printf("%d",A[l-1]);
 
  printf("\n");
  
  for(i=1;i<l;i++)
    {
      key = A[i];

      j = i-1;
      
      while(j>=0 && A[j]>key)
	{
	  A[j+1] = A[j];
	  j--;
	}
  
      A[j+1] = key;
      
      for(k=0;k<l-1;k++)
	{
	  printf("%d ",A[k]);
	}

      printf("%d",A[l-1]);
      
      printf("\n");
     
    }

  return 0;
}
