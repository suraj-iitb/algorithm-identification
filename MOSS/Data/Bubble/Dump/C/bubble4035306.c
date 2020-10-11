#include<stdio.h>
#define N 100

int main()
{
  int n,A[N],i,flag,cnt=0,change,j;
  
  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }



  flag = 1;
  i=0;
  while(flag)
    {
      flag = 0;
      for(j=n-1;j>=i+1;j--)
	{
	  if(A[j] < A[j-1])
	    {
	      change = A[j];
	      A[j] = A[j-1];
	      A[j-1] = change;
	      flag = 1;
	      cnt++;
	    }
	 
	}
      i++;
    }


  for(j=0;j<n;j++)
    {
      printf("%d",A[j]);
      if(j !=n-1)printf(" ");
    }
  printf("\n%d\n",cnt);
  
  return 0;
}



