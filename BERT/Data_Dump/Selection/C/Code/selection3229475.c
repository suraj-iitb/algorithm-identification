#include<stdio.h>

int main()
{
  int n;
  int arr[100];
  int count = 0;
  int p;
  int temp;

  scanf("%d", &n);

  for(int i = 0 ; i < n; i++)
    {
      scanf("%d", &arr[i]);
    }
  
  for(int i = 0; i < n-1; i++)
    {
      p = i;
      for(int j = i; j < n; j++)
	{
	  if(arr[j] < arr[p])
	    {
	      p = j;
	    }
	}
      	  if(p != i)
	    {
	      temp = arr[i];
	      arr[i] = arr[p];
	      arr[p] = temp;
	      count++;
	    }
    }
  for(int i = 0; i < n; i++)
    {
      if(i == n-1)
	{
	  printf("%d\n", arr[i]);
	  break;
	}
      printf("%d ", arr[i]);
    }
  printf("%d\n", count);
}

