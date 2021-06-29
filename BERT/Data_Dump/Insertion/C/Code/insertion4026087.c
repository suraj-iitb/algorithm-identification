#include <stdio.h>
int main()
{
  int x,i,j,key,A[100],k;
  scanf("%d",&x);
  for(i=0;i<x;i++)
      scanf("%d",&A[i]);
  
  for(i=0;i<x;i++)
    {
      key = A[i];
      j = i-1;
      while(j>=0 && A[j]>key)
	    {   
	        A[j+1] = A[j];
	        j = j-1;
	    }
      A[j+1] = key;
      for(k = 0; k < x; k++)
        {
            printf("%d",A[k]);
            if(k < x-1)
            {
                printf(" ");
            }
        }
      printf("\n");
    }
  return 0;
}
