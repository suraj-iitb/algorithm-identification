#include <stdio.h>

void screen(int[] ,int);

#define N 100
int main()
{
  int i,j,count=0,flag;
  int n,A[N];
  int temp;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)//scan A[]
    {
      scanf("%d",&A[i]);
    }

  /*for(i=n-1;i>0;i--)//bubble sort
    {
    for(j=i-1;j>=0;j--)
    {
    if(A[j]>A[j+1])
    {
    temp = A[j+1];
    A[j+1]=A[j];
    A[j]=temp;
    count++;
    screen(A,n);
    }
    else break;
    }
    }*/
  while(1)
    {
      flag=0;
      for(j=n-1;j>0;j--)
	{
	  
	  if(A[j-1]>A[j])
	    {
	      temp = A[j];
	      A[j] = A[j-1];
	      A[j-1] = temp;
	      count++;
	      flag++;
	      //screen(A,n);
	    }
	}
      if(flag==0)
	{
	  break;
	}
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

