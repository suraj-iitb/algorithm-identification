//Binary search

#include<stdio.h>

int main()
{

  int n1 = 0;
  int n2 = 0;
  int i,j;
  int arr1[100000];
  int arr2[50000];
  int mid = 0;
  int count = 0;
  int left = 0;
  int right = 0;

  //input data
  scanf("%d",&n1);

  for(i = 0; i < n1; i++)
    {
      scanf("%d",&arr1[i]);
    }

  scanf("%d",&n2);

  for(j = 0; j < n2; j++)
    {
      scanf("%d",&arr2[j]);
    }

  //work time

  for(j = 0; j < n2 ;j++)
    {
      left = 0;
      right = n1;

      while(left < right)
	{
        
	  mid = (left + right) / 2;
     
	  if(arr1[mid] == arr2[j])
	    {
	      count++;
	      break;
	    }

	  else if(arr2[j] < arr1[mid]) right = mid;

	  else if(arr2[j] > arr1[mid]) left = mid + 1;

	}
    }

  //output data
  printf("%d\n",count);

  return 0;
}


