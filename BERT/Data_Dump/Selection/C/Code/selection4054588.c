#include <stdio.h>

void screen(int[] ,int);

#define N 100
int main()
{
  int i=0,k=0,min=0,minj=0,count=0;
  int n=0,A[N];
  int temp=0;
  int flag=0,cflag=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)//scan A[]
    {
      scanf("%d",&A[i]);
    }

  for(i=0;i<n;i++)//bubble sort
    {
      cflag=0;
      min = A[i];
      minj = i;
      for(k=i+1;k<n;k++)
	{
	  if(min>A[k])
	    {
	      min = A[k];
	      minj = k;
	      cflag = 1;
	    }
	}

      temp = A[i];
      A[i] = min;
      A[minj] = temp;
      if(cflag == 1){count++;}
      
      flag=0;
      for(k=1;k<n;k++)//syu u ryo u ha n te i
	{
	  if(A[k-1]>A[k])
	    {
	      flag = 2;
	    }
	}
      if(flag == 0)break;
      //screen(A,n);
    }
  
  screen(A,n);
  printf("%d\n",count);
  return 0;
}

void screen (int A[], int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      if(i<n-1)
	{
	  printf("%d ",A[i]);
	}
      else if(i==(n-1))
	{
	  printf("%d",A[i]);
	  break;
	}
    }
  printf("\n");
}

