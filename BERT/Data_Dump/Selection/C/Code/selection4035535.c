#include <stdio.h>
int main()
{
  int x,i,j,key,A[100],k,minj,count = 0;
  scanf("%d",&x);
  for(i = 0; i < x; i++)
    scanf("%d",&A[i]);
  
  for(i = 0; i < x; i++)
    {
      minj = i;
      for(j = i; j < x; j++)
	{
	  if(A[j] < A[minj])
	    {
	      minj = j;
	      
	    } 
	}
      key = A[i];
      A[i] = A[minj];
      A[minj] = key;
      if(A[i] != A[minj])
	count++;
    }
  
  for(k = 0; k < x; k++)
    {
      printf("%d",A[k]);
      if(k < x-1)
	printf(" ");
    }
  printf("\n%d\n",count);
    
  return 0;
}
