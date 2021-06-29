#include<stdio.h>
int main()
{
  int n,i,A[100],B,flag=1,j=0;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }



  while(flag)
    {
      flag=0;
      for(i=n-1;i>=1;i--)
	{
	  if(A[i]<A[i-1])
	    {
	    B=A[i];
	    A[i]=A[i-1];
	    A[i-1]=B;
	    flag=1;
	    j++;
	    }
	}
    }

for(i=0;i<n-1;i++)
    {
  printf("%d ",A[i]);
    }
printf("%d\n",A[n-1]);
 printf("%d\n",j);
 
  return 0;
}
