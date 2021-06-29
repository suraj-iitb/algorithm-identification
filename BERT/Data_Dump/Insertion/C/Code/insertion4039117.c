#include<stdio.h>

int main()
{
  int l,i,j,k,v;

  scanf("%d",&l);

  int A[l];
  
  for(i=0;i<l;i++)
    {
      scanf("%d",&A[i]);
    }

  for(i=0;i<l;i++)
    {
      v = A[i];
      j=i-1;
      
      while(j>=0&&A[j]>v)
	{
	  A[j+1]=A[j];
	  j--;
	  A[j+1]=v;
	}
      for(k=0;k<l-1;k++)
	{
	  printf("%d ",A[k]);
	}
      printf("%d\n",A[k]);
  
    }
  
  return 0;
}

  
