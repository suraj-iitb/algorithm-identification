//Select sort

#include<stdio.h>
#define N 100

void sel(void);

int i = 0,arr[N];
int n = 0;
int k = 0;
int minj = 0;
int j = 0;
int count = 0;
int temp = 0;

int main()
{

  //input data
  scanf("%d",&n);

  for(i = 0;i < n;i++)
    {
      scanf("%d",&arr[i]);
    }

  //calculate
  sel();

  //output data
  printf("%d",arr[0]);

  for(k = 1; k < n;k++)
    {
      printf(" %d",arr[k]);
    }
  printf("\n");

  printf("%d\n",count);

  return 0;
}

void sel(void)
{
  for(i = 0; i < n - 1; i++)
    {
      minj = i;
    
      //for(j = n - 1; j > i; j--)
      for(j = i+1; j<n;j++)
	{ 
	  if(arr[j] < arr[minj])
	    {
	      minj = j;
	    }
	}

      if(minj != i)
      {
	  temp = arr[i];
	  arr[i] = arr[minj];
	  arr[minj] = temp;
   
	  count++;
	  }
    }
}

