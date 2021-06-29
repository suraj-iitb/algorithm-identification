//Bubble Sort

#include<stdio.h>
#define N 100

void bubble(void);
int i = 0,arr[N];
int n = 0;
int j = 0;
int temp = 0;
int k = 0;
int count = 0;

int main()
{

  //input data
  scanf("%d",&n);

  for(i=0 ; i<n ; i++)
    {
      scanf("%d",&arr[i]);
    }

  //output data
  bubble();

  printf("%d",arr[0]);

  for(k = 1; k < n; k++)
    {
      printf(" %d",arr[k]);
    }
  printf("\n");

  printf("%d\n",count);

  return 0;
  
}

void bubble(void)
{
  int flag = 0;

  flag = 1;
  i = 0;

  while(flag)
    {
     
      flag = 0;
      j = n - 1;
      
      for( ;j >= i+1 ; j--)
	{
	  if(arr[j] < arr[j - 1])
	    {
	     
	      temp = arr[j];
	      arr[j] = arr[j-1];
	      arr[j-1] = temp;
	      flag = 1;
	      count++;
	    }
	}
      i++;
    
    }
 
}

